/*
 * This file is part of attach-f-p strace test.
 *
 * Copyright (c) 2016 Dmitry V. Levin <ldv@altlinux.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "tests.h"
#include <assert.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/syscall.h>
#include <unistd.h>

#define N 3

typedef union {
	void *ptr;
	pid_t pid;
} retval_t;

typedef struct {
	sigset_t set;
	unsigned int no;
} thread_arg_t;

static const char text_parent[] = "attach-f-p.test parent";
static const char *child[N] = {
	"attach-f-p.test child 0",
	"attach-f-p.test child 1",
	"attach-f-p.test child 2"
};
static const int sigs[N] = { SIGALRM, SIGUSR1, SIGUSR2 };
static const struct itimerspec its[N] = {
	{ .it_value.tv_nsec = 500000000 },
	{ .it_value.tv_nsec = 700000000 },
	{ .it_value.tv_nsec = 900000000 },
};
static thread_arg_t args[N] = {
	{ .no = 0 },
	{ .no = 1 },
	{ .no = 2 }
};

static void *
thread(void *a)
{
	thread_arg_t *arg = a;
	int signo;
	errno = sigwait(&arg->set, &signo);
	if (errno)
		perror_msg_and_fail("sigwait");
	assert(chdir(child[arg->no]) == -1);
	retval_t retval = { .pid = syscall(__NR_gettid) };
	return retval.ptr;
}

int
main(void)
{
	pthread_t t[N];
	unsigned int i;

	for (i = 0; i < N; ++i) {
		sigemptyset(&args[i].set);
		sigaddset(&args[i].set, sigs[i]);

		errno = pthread_sigmask(SIG_BLOCK, &args[i].set, NULL);
		if (errno)
			perror_msg_and_fail("pthread_sigmask");
	}

	for (i = 0; i < N; ++i) {
		struct sigevent sev = {
			.sigev_notify = SIGEV_SIGNAL,
			.sigev_signo = sigs[i]
		};
		timer_t timerid;
		if (timer_create(CLOCK_MONOTONIC, &sev, &timerid))
			perror_msg_and_skip("timer_create");

		if (timer_settime(timerid, 0, &its[i], NULL))
			perror_msg_and_fail("timer_settime");

		errno = pthread_create(&t[i], NULL, thread, (void *) &args[i]);
		if (errno)
			perror_msg_and_fail("pthread_create");
	}

	if (write(3, "\n", 1) != 1)
		perror_msg_and_fail("write");

	for (i = 0; i < N; ++i) {
		retval_t retval;
		errno = pthread_join(t[i], &retval.ptr);
		if (errno)
			perror_msg_and_fail("pthread_join");
		errno = ENOENT;
		printf("%-5d chdir(\"%s\") = -1 ENOENT (%m)\n"
		       "%-5d +++ exited with 0 +++\n",
		       retval.pid, child[i], retval.pid);
	}

	pid_t pid = getpid();
	assert(chdir(text_parent) == -1);

	printf("%-5d chdir(\"%s\") = -1 ENOENT (%m)\n"
	       "%-5d +++ exited with 0 +++\n", pid, text_parent, pid);

	return 0;
}
