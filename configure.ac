# Configure template for strace.
#
# Copyright (c) 1999-2001 Wichert Akkerman <wichert@deephackmode.org>
# Copyright (c) 2002-2009 Roland McGrath <roland@redhat.com>
# Copyright (c) 2006-2016 Dmitry V. Levin <ldv@altlinux.org>
# Copyright (c) 2008-2015 Mike Frysinger <vapier@gentoo.org>
# Copyright (c) 2015 Elvira Khabirova <lineprinter0@gmail.com>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

AC_PREREQ(2.57)
AC_INIT([strace],
	m4_esyscmd([./git-version-gen .tarball-version]),
	[strace-devel@lists.sourceforge.net])
AC_CONFIG_SRCDIR([strace.c])
AC_CONFIG_AUX_DIR([.])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign nostdinc dist-xz no-dist-gzip silent-rules parallel-tests])
AM_MAINTAINER_MODE
AC_CANONICAL_HOST

AC_PROG_CC
AC_PROG_CPP
AX_PROG_CC_FOR_BUILD
AC_PROG_INSTALL
AC_PROG_RANLIB

AC_USE_SYSTEM_EXTENSIONS
AX_CODE_COVERAGE

AC_MSG_CHECKING([for supported architecture])
arch_m32=
arch_mx32=
case "$host_cpu" in
bfin)
	arch=bfin
	AC_DEFINE([BFIN], 1, [Define for the Blackfin architecture.])
	;;
i[[3456]]86|pentium)
	arch=i386
	AC_DEFINE([I386], 1, [Define for the i386 architecture.])
	;;
ia64)
	arch=ia64
	AC_DEFINE([IA64], 1, [Define for the IA64 architecture.])
	;;
m68k)
	arch=m68k
	AC_DEFINE([M68K], 1, [Define for the m68k architecture.])
	;;
sparc64*)
	arch=sparc64
	arch_m32=sparc
	AC_DEFINE([SPARC64], 1, [Define for the SPARC64 architecture.])
	;;
sparc*)
	arch=sparc
	AC_DEFINE([SPARC], 1, [Define for the SPARC architecture.])
	;;
metag*)
	arch=metag
	AC_DEFINE([METAG], 1, [Define for the Meta architecture.])
	;;
mips*)
	arch=mips
	AC_DEFINE([MIPS], 1, [Define for the MIPS architecture.])
	;;
alpha*)
	arch=alpha
	AC_DEFINE([ALPHA], 1, [Define for the Alpha architecture.])
	;;
powerpc*)
	AC_DEFINE([POWERPC], 1, [Define for the PowerPC architecture.])
	AC_TRY_COMPILE(
[#ifndef __LP64__
# error 32 bit
#endif], [], arch=powerpc64, arch=powerpc)
	if test "$arch" = "powerpc64"; then
		arch_m32=powerpc
		AC_DEFINE([POWERPC64], 1, [Define for the PowerPC64 architecture.])
	fi
	;;
arm*)
	arch=arm
	AC_DEFINE([ARM], 1, [Define for the ARM architecture.])
	;;
aarch64*)
	arch=aarch64
	arch_m32=arm
	AC_DEFINE([AARCH64], 1, [Define for the AArch64 architecture.])
	;;
avr32*)
	arch=avr32
	AC_DEFINE([AVR32], 1, [Define for the AVR32 architecture.])
	;;
arc*)
	arch=arc
	AC_DEFINE([ARC], 1, [Define for the ARC architecture.])
	;;
s390)
	arch=s390
	AC_DEFINE([S390], 1, [Define for the S390 architecture.])
	;;
s390x)
	arch=s390x
	AC_DEFINE([S390X], 1, [Define for the S390x architecture.])
	;;
hppa*|parisc*)
	arch=hppa
	AC_DEFINE([HPPA], 1, [Define for the HPPA architecture.])
	;;
sh64*)
	arch=sh64
	AC_DEFINE([SH64], 1, [Define for the SH64 architecture.])
	;;
sh*)
	arch=sh
	AC_DEFINE([SH], 1, [Define for the SH architecture.])
	;;
x86?64*)
	arch_m32=i386
	AC_TRY_COMPILE(
[#ifndef __ILP32__
# error not x32
#endif], [], arch=x32, arch=x86_64)
	if test "$arch" = "x86_64"; then
		arch_mx32=x32
		AC_DEFINE([X86_64], 1, [Define for the 64bit AMD x86-64 architecture.])
	else
		AC_DEFINE([X32], 1, [Define for the 32bit AMD x86-64 architecture.])
	fi
	;;
cris|crisv10)
	arch=crisv10
	AC_DEFINE([CRISV10], 1, [Define for the CRISv10 architecture.])
	;;
crisv32)
	arch=crisv32
	AC_DEFINE([CRISV32], 1, [Define for the CRISv32 architecture.])
	;;
tile*)
	arch=tile
	AC_DEFINE([TILE], 1, [Define for the Tile architecture])
	;;
microblaze*)
	arch=microblaze
	AC_DEFINE([MICROBLAZE], 1, [Define for the MicroBlaze architecture.])
	;;
nios2*)
	arch=nios2
	AC_DEFINE([NIOS2], 1, [Define for the Nios-II architecture.])
	;;

or1k*)
	arch=or1k
	AC_DEFINE([OR1K], 1, [Define for the OpenRISC 1000 architecture.])
	;;

xtensa*)
	arch=xtensa
	AC_DEFINE([XTENSA], 1, [Define for the Xtensa architecture])
	;;

*)
	AC_MSG_RESULT([NO!])
	AC_MSG_ERROR([architecture $host_cpu is not supported by strace])
	;;
esac
AC_MSG_RESULT($arch)

test -n "$arch_m32" ||
	arch_m32=$arch
test -n "$arch_mx32" ||
	arch_mx32=$arch
AC_SUBST(arch)
AC_SUBST(arch_m32)
AC_SUBST(arch_mx32)

if test "$arch" = mips; then
	AC_CACHE_CHECK([for _MIPS_SIM], [st_cv__MIPS_SIM],
		       [AC_COMPUTE_INT([st_cv__MIPS_SIM], [_MIPS_SIM],
				       [#include <sgidefs.h>],
				       [AC_MSG_ERROR([_MIPS_SIM cannot be determined])])])

	AC_CACHE_CHECK([for MIPS ABI], [st_cv_mips_abi],
		[AC_COMPILE_IFELSE(
			[AC_LANG_PROGRAM([[#include <sgidefs.h>]],
					 [[int i[_MIPS_SIM == _MIPS_SIM_ABI32 ? 1 : - 1];]])],
			[st_cv_mips_abi=o32],
		[AC_COMPILE_IFELSE(
			[AC_LANG_PROGRAM([[#include <sgidefs.h>]],
					 [[int i[_MIPS_SIM == _MIPS_SIM_NABI32 ? 1 : - 1];]])],
			[st_cv_mips_abi=n32],
		[AC_COMPILE_IFELSE(
			[AC_LANG_PROGRAM([[#include <sgidefs.h>]],
					 [[int i[_MIPS_SIM == _MIPS_SIM_ABI64 ? 1 : - 1];]])],
			[st_cv_mips_abi=n64],
			[st_cv_mips_abi=unknown])])])])

	case "$st_cv_mips_abi" in
		o32) AC_DEFINE([LINUX_MIPSO32], [1], [Define for _MIPS_SIM_ABI32.]);;
		n32) AC_DEFINE([LINUX_MIPSN32], [1], [Define for _MIPS_SIM_NABI32.]);;
		n64) AC_DEFINE([LINUX_MIPSN64], [1], [Define for _MIPS_SIM_ABI64.]);;
		*) AC_MSG_ERROR([Unsupported _MIPS_SIM]);;
	esac
fi

AC_ARG_ENABLE([arm-oabi],
	      [AS_HELP_STRING([--enable-arm-oabi],
			      [enable OABI support on ARM EABI])],
	      [], [enable_arm_oabi=no])
case "$enable_arm_oabi" in
	yes) enable_arm_oabi=1 ;;
	no) enable_arm_oabi=0 ;;
	*) AC_MSG_ERROR([bad value $enable_arm_oabi for arm-oabi option]) ;;
esac
AC_DEFINE_UNQUOTED([ENABLE_ARM_OABI], [$enable_arm_oabi],
		   [Define to 1 if you want OABI support on ARM EABI.])

gl_WARN_ADD([-Wall])
gl_WARN_ADD([-Wwrite-strings])
gl_WARN_ADD([-Wsign-compare])
AC_ARG_ENABLE([gcc-Werror],
  [AS_HELP_STRING([--enable-gcc-Werror], [turn on gcc's -Werror option])],
  [case $enableval in
     yes) gl_WARN_ADD([-Werror]) ;;
     no)  ;;
     *)   AC_MSG_ERROR([bad value $enableval for gcc-Werror option]) ;;
   esac]
)
AC_SUBST([WARN_CFLAGS])

AC_C_BIGENDIAN
AC_C_CONST
AC_C_TYPEOF

AC_TYPE_GETGROUPS
AC_TYPE_MODE_T
AC_TYPE_SIGNAL
AC_TYPE_UID_T

AC_HEADER_DIRENT
AC_HEADER_MAJOR
AC_HEADER_STAT
AC_HEADER_STDBOOL
AC_HEADER_STDC

AC_CHECK_FUNCS(m4_normalize([
	fanotify_mark
	fopen64
	fork
	fputs_unlocked
	fstatat
	ftruncate
	futimens
	if_indextoname
	inet_ntop
	inet_pton
	pipe2
	prctl
	preadv
	process_vm_readv
	pwritev
	recvmmsg
	sendmmsg
	sigaction
	signalfd
	stpcpy
	strerror
	strsignal
	utimensat
]))

AC_CHECK_TYPES([sig_atomic_t, struct sigcontext],,, [#include <signal.h>])

AC_CHECK_TYPES([struct mmsghdr],,, [#include <sys/socket.h>])

AC_CHECK_TYPES([__kernel_long_t, __kernel_ulong_t],,,
[#include <asm/posix_types.h>])

AC_CHECK_TYPES([struct stat64, struct __old_kernel_stat],,,
[#include <sys/types.h>
#include <asm/stat.h>])

AC_CHECK_TYPES([struct statfs64],,, [#include <sys/vfs.h>])

AC_CHECK_TYPES(m4_normalize([
	struct pt_all_user_regs,
	struct ia64_fpreg,
	struct ptrace_peeksiginfo_args
]),,, [#include <sys/ptrace.h>])

AC_CHECK_TYPES(m4_normalize([
	struct flock,
	struct flock64,
	struct __kernel_flock,
	struct __kernel_flock64
]),,,
[#include <sys/types.h>
#include <linux/fcntl.h>])

AC_CHECK_MEMBERS(m4_normalize([
	struct stat.st_atim.tv_nsec,
	struct stat.st_blksize,
	struct stat.st_blocks,
	struct stat.st_ctim.tv_nsec,
	struct stat.st_flags,
	struct stat.st_fstype,
	struct stat.st_gen,
	struct stat.st_mtim.tv_nsec,
	struct stat.st_rdev
]))

AC_CHECK_MEMBERS([struct msghdr.msg_control],,, [#include <sys/socket.h>])

AC_CHECK_MEMBERS([struct timex.tai],,, [#include <sys/timex.h>])

AC_CHECK_MEMBERS([struct utsname.domainname],,, [#include <sys/utsname.h>])

AC_CHECK_MEMBERS([struct sockaddr_in6.sin6_scope_id],,,
[#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>])

AC_CHECK_MEMBERS(m4_normalize([
	struct stat.st_atime_nsec,
	struct stat.st_ctime_nsec,
	struct stat.st_mtime_nsec
]),,, [#include <sys/types.h>
#include <asm/stat.h>])

AC_CHECK_MEMBERS(m4_normalize([
	siginfo_t.si_syscall,
	siginfo_t.si_timerid,
	siginfo_t.si_overrun
]),,, [#include <signal.h>])

AC_CHECK_HEADERS(m4_normalize([
	asm/cachectl.h
	asm/sysmips.h
	bluetooth/bluetooth.h
	elf.h
	inttypes.h
	ioctls.h
	linux/bsg.h
	linux/falloc.h
	linux/filter.h
	linux/hiddev.h
	linux/ip_vs.h
	linux/ipc.h
	linux/mmtimer.h
	linux/msg.h
	linux/perf_event.h
	linux/seccomp.h
	linux/securebits.h
	linux/sem.h
	linux/shm.h
	linux/utsname.h
	mqueue.h
	netinet/sctp.h
	scsi/sg.h
	stropts.h
	sys/conf.h
	sys/epoll.h
	sys/eventfd.h
	sys/fanotify.h
	sys/ioctl.h
	sys/ipc.h
	sys/msg.h
	sys/reg.h
	sys/sem.h
	sys/shm.h
	sys/signalfd.h
	sys/vfs.h
	sys/xattr.h
]))

AC_CHECK_HEADERS([asm/sigcontext.h],,, [#include <signal.h>])

AC_CHECK_HEADERS([netinet/tcp.h netinet/udp.h],,, [#include <netinet/in.h>])

AC_CHECK_HEADERS([linux/mqueue.h],,, [#include <linux/types.h>])

AC_CHECK_HEADERS([linux/icmp.h linux/in6.h linux/netlink.h linux/if_packet.h],,,
[#include <stddef.h>
#include <sys/socket.h>
#include <asm/types.h>])

AC_CHECK_HEADERS(m4_normalize([
	linux/netfilter_arp/arp_tables.h
	linux/netfilter_bridge/ebtables.h
	linux/netfilter_ipv4/ip_tables.h
	linux/netfilter_ipv6/ip6_tables.h
]),,, [#include <netinet/in.h>
#include <net/if.h>])

AC_CHECK_HEADERS([linux/input.h], [
	AC_CHECK_MEMBERS([struct input_absinfo.resolution],,, [#include <linux/input.h>])
])

AC_CHECK_HEADERS([linux/bpf.h], [
	AC_CACHE_CHECK([whether union bpf_attr.log_buf initialization works],
		       [st_cv_have_union_bpf_attr_log_buf],
		[AC_COMPILE_IFELSE(
			[AC_LANG_PROGRAM([[#include <linux/bpf.h>]],
					 [[union bpf_attr a = { .log_buf = 0 };]])],
			[st_cv_have_union_bpf_attr_log_buf=yes],
			[st_cv_have_union_bpf_attr_log_buf=no])])
	if test $st_cv_have_union_bpf_attr_log_buf = yes; then
		AC_DEFINE(HAVE_UNION_BPF_ATTR_LOG_BUF, [1],
			  [Define to 1 if union bpf_attr.log_buf initialization works])
	fi
])

AC_CHECK_DECLS([sys_errlist])
AC_CHECK_DECLS(m4_normalize([
	PTRACE_PEEKUSER,
	PTRACE_POKEUSER
]),,, [#include <sys/ptrace.h>])

AC_CHECK_DECLS(m4_normalize([
	P_PID,
	P_PPID,
	P_PGID,
	P_SID,
	P_CID,
	P_UID,
	P_GID,
	P_ALL,
	P_LWPID
]),,, [#include <sys/wait.h>])

AC_CHECK_DECLS(m4_normalize([
	LO_FLAGS_READ_ONLY,
	LO_FLAGS_AUTOCLEAR,
	LO_FLAGS_PARTSCAN
]),,, [#include <linux/loop.h>])

AC_CHECK_DECLS(m4_normalize([
	CTL_KERN,
	CTL_VM,
	CTL_NET,
	CTL_PROC,
	CTL_FS,
	CTL_DEBUG,
	CTL_DEV,
	CTL_BUS,
	CTL_ABI,
	CTL_CPU,
	CTL_ARLAN,
	CTL_S390DBF,
	CTL_SUNRPC,
	CTL_PM,
	CTL_FRV,
	KERN_OSTYPE,
	KERN_OSRELEASE,
	KERN_OSREV,
	KERN_VERSION,
	KERN_SECUREMASK,
	KERN_PROF,
	KERN_NODENAME,
	KERN_DOMAINNAME,
	KERN_PANIC,
	KERN_REALROOTDEV,
	KERN_SPARC_REBOOT,
	KERN_CTLALTDEL,
	KERN_PRINTK,
	KERN_NAMETRANS,
	KERN_PPC_HTABRECLAIM,
	KERN_PPC_ZEROPAGED,
	KERN_PPC_POWERSAVE_NAP,
	KERN_MODPROBE,
	KERN_SG_BIG_BUFF,
	KERN_ACCT,
	KERN_PPC_L2CR,
	KERN_RTSIGNR,
	KERN_RTSIGMAX,
	KERN_SHMMAX,
	KERN_MSGMAX,
	KERN_MSGMNB,
	KERN_MSGPOOL,
	KERN_SYSRQ,
	KERN_MAX_THREADS,
	KERN_RANDOM,
	KERN_SHMALL,
	KERN_MSGMNI,
	KERN_SEM,
	KERN_SPARC_STOP_A,
	KERN_SHMMNI,
	KERN_OVERFLOWUID,
	KERN_OVERFLOWGID,
	KERN_SHMPATH,
	KERN_HOTPLUG,
	KERN_IEEE_EMULATION_WARNINGS,
	KERN_S390_USER_DEBUG_LOGGING,
	KERN_CORE_USES_PID,
	KERN_TAINTED,
	KERN_CADPID,
	KERN_PIDMAX,
	KERN_CORE_PATTERN,
	KERN_PANIC_ON_OOPS,
	KERN_HPPA_PWRSW,
	KERN_HPPA_UNALIGNED,
	KERN_PRINTK_RATELIMIT,
	KERN_PRINTK_RATELIMIT_BURST,
	KERN_PTY,
	KERN_NGROUPS_MAX,
	KERN_SPARC_SCONS_PWROFF,
	KERN_HZ_TIMER,
	KERN_UNKNOWN_NMI_PANIC,
	KERN_BOOTLOADER_TYPE,
	KERN_RANDOMIZE,
	KERN_SETUID_DUMPABLE,
	KERN_SPIN_RETRY,
	KERN_ACPI_VIDEO_FLAGS,
	KERN_IA64_UNALIGNED,
	KERN_COMPAT_LOG,
	KERN_MAX_LOCK_DEPTH,
	KERN_NMI_WATCHDOG,
	KERN_PANIC_ON_NMI,
	NET_CORE,
	NET_ETHER,
	NET_802,
	NET_UNIX,
	NET_IPV4,
	NET_IPX,
	NET_ATALK,
	NET_NETROM,
	NET_AX25,
	NET_BRIDGE,
	NET_ROSE,
	NET_IPV6,
	NET_X25,
	NET_TR,
	NET_DECNET,
	NET_ECONET,
	NET_SCTP,
	NET_LLC,
	NET_NETFILTER,
	NET_DCCP,
	NET_IRDA,
	NET_CORE_WMEM_MAX,
	NET_CORE_RMEM_MAX,
	NET_CORE_WMEM_DEFAULT,
	NET_CORE_RMEM_DEFAULT,
	NET_CORE_DESTROY_DELAY,
	NET_CORE_MAX_BACKLOG,
	NET_CORE_FASTROUTE,
	NET_CORE_MSG_COST,
	NET_CORE_MSG_BURST,
	NET_CORE_OPTMEM_MAX,
	NET_CORE_HOT_LIST_LENGTH,
	NET_CORE_DIVERT_VERSION,
	NET_CORE_NO_CONG_THRESH,
	NET_CORE_NO_CONG,
	NET_CORE_LO_CONG,
	NET_CORE_MOD_CONG,
	NET_CORE_DEV_WEIGHT,
	NET_CORE_SOMAXCONN,
	NET_CORE_BUDGET,
	NET_CORE_AEVENT_ETIME,
	NET_CORE_AEVENT_RSEQTH,
	NET_CORE_WARNINGS,
	NET_IPV4_FORWARD,
	NET_IPV4_DYNADDR,
	NET_IPV4_CONF,
	NET_IPV4_NEIGH,
	NET_IPV4_ROUTE,
	NET_IPV4_FIB_HASH,
	NET_IPV4_NETFILTER,
	NET_IPV4_TCP_TIMESTAMPS,
	NET_IPV4_TCP_WINDOW_SCALING,
	NET_IPV4_TCP_SACK,
	NET_IPV4_TCP_RETRANS_COLLAPSE,
	NET_IPV4_DEFAULT_TTL,
	NET_IPV4_AUTOCONFIG,
	NET_IPV4_NO_PMTU_DISC,
	NET_IPV4_TCP_SYN_RETRIES,
	NET_IPV4_IPFRAG_HIGH_THRESH,
	NET_IPV4_IPFRAG_LOW_THRESH,
	NET_IPV4_IPFRAG_TIME,
	NET_IPV4_TCP_MAX_KA_PROBES,
	NET_IPV4_TCP_KEEPALIVE_TIME,
	NET_IPV4_TCP_KEEPALIVE_PROBES,
	NET_IPV4_TCP_RETRIES1,
	NET_IPV4_TCP_RETRIES2,
	NET_IPV4_TCP_FIN_TIMEOUT,
	NET_IPV4_IP_MASQ_DEBUG,
	NET_TCP_SYNCOOKIES,
	NET_TCP_STDURG,
	NET_TCP_RFC1337,
	NET_TCP_SYN_TAILDROP,
	NET_TCP_MAX_SYN_BACKLOG,
	NET_IPV4_LOCAL_PORT_RANGE,
	NET_IPV4_ICMP_ECHO_IGNORE_ALL,
	NET_IPV4_ICMP_ECHO_IGNORE_BROADCASTS,
	NET_IPV4_ICMP_SOURCEQUENCH_RATE,
	NET_IPV4_ICMP_DESTUNREACH_RATE,
	NET_IPV4_ICMP_TIMEEXCEED_RATE,
	NET_IPV4_ICMP_PARAMPROB_RATE,
	NET_IPV4_ICMP_ECHOREPLY_RATE,
	NET_IPV4_ICMP_IGNORE_BOGUS_ERROR_RESPONSES,
	NET_IPV4_IGMP_MAX_MEMBERSHIPS,
	NET_TCP_TW_RECYCLE,
	NET_IPV4_ALWAYS_DEFRAG,
	NET_IPV4_TCP_KEEPALIVE_INTVL,
	NET_IPV4_INET_PEER_THRESHOLD,
	NET_IPV4_INET_PEER_MINTTL,
	NET_IPV4_INET_PEER_MAXTTL,
	NET_IPV4_INET_PEER_GC_MINTIME,
	NET_IPV4_INET_PEER_GC_MAXTIME,
	NET_TCP_ORPHAN_RETRIES,
	NET_TCP_ABORT_ON_OVERFLOW,
	NET_TCP_SYNACK_RETRIES,
	NET_TCP_MAX_ORPHANS,
	NET_TCP_MAX_TW_BUCKETS,
	NET_TCP_FACK,
	NET_TCP_REORDERING,
	NET_TCP_ECN,
	NET_TCP_DSACK,
	NET_TCP_MEM,
	NET_TCP_WMEM,
	NET_TCP_RMEM,
	NET_TCP_APP_WIN,
	NET_TCP_ADV_WIN_SCALE,
	NET_IPV4_NONLOCAL_BIND,
	NET_IPV4_ICMP_RATELIMIT,
	NET_IPV4_ICMP_RATEMASK,
	NET_TCP_TW_REUSE,
	NET_TCP_FRTO,
	NET_TCP_LOW_LATENCY,
	NET_IPV4_IPFRAG_SECRET_INTERVAL,
	NET_IPV4_IGMP_MAX_MSF,
	NET_TCP_NO_METRICS_SAVE,
	NET_TCP_DEFAULT_WIN_SCALE,
	NET_TCP_MODERATE_RCVBUF,
	NET_TCP_TSO_WIN_DIVISOR,
	NET_TCP_BIC_BETA,
	NET_IPV4_ICMP_ERRORS_USE_INBOUND_IFADDR,
	NET_TCP_CONG_CONTROL,
	NET_TCP_ABC,
	NET_IPV4_IPFRAG_MAX_DIST,
	NET_TCP_MTU_PROBING,
	NET_TCP_BASE_MSS,
	NET_IPV4_TCP_WORKAROUND_SIGNED_WINDOWS,
	NET_TCP_DMA_COPYBREAK,
	NET_TCP_SLOW_START_AFTER_IDLE,
	NET_CIPSOV4_CACHE_ENABLE,
	NET_CIPSOV4_CACHE_BUCKET_SIZE,
	NET_CIPSOV4_RBM_OPTFMT,
	NET_CIPSOV4_RBM_STRICTVALID,
	NET_TCP_AVAIL_CONG_CONTROL,
	NET_TCP_ALLOWED_CONG_CONTROL,
	NET_TCP_MAX_SSTHRESH,
	NET_TCP_FRTO_RESPONSE,
	NET_IPV4_ROUTE_FLUSH,
	NET_IPV4_ROUTE_MIN_DELAY,
	NET_IPV4_ROUTE_MAX_DELAY,
	NET_IPV4_ROUTE_GC_THRESH,
	NET_IPV4_ROUTE_MAX_SIZE,
	NET_IPV4_ROUTE_GC_MIN_INTERVAL,
	NET_IPV4_ROUTE_GC_TIMEOUT,
	NET_IPV4_ROUTE_GC_INTERVAL,
	NET_IPV4_ROUTE_REDIRECT_LOAD,
	NET_IPV4_ROUTE_REDIRECT_NUMBER,
	NET_IPV4_ROUTE_REDIRECT_SILENCE,
	NET_IPV4_ROUTE_ERROR_COST,
	NET_IPV4_ROUTE_ERROR_BURST,
	NET_IPV4_ROUTE_GC_ELASTICITY,
	NET_IPV4_ROUTE_MTU_EXPIRES,
	NET_IPV4_ROUTE_MIN_PMTU,
	NET_IPV4_ROUTE_MIN_ADVMSS,
	NET_IPV4_ROUTE_SECRET_INTERVAL,
	NET_IPV4_ROUTE_GC_MIN_INTERVAL_MS,
	NET_IPV4_CONF_FORWARDING,
	NET_IPV4_CONF_MC_FORWARDING,
	NET_IPV4_CONF_PROXY_ARP,
	NET_IPV4_CONF_ACCEPT_REDIRECTS,
	NET_IPV4_CONF_SECURE_REDIRECTS,
	NET_IPV4_CONF_SEND_REDIRECTS,
	NET_IPV4_CONF_SHARED_MEDIA,
	NET_IPV4_CONF_RP_FILTER,
	NET_IPV4_CONF_ACCEPT_SOURCE_ROUTE,
	NET_IPV4_CONF_BOOTP_RELAY,
	NET_IPV4_CONF_LOG_MARTIANS,
	NET_IPV4_CONF_TAG,
	NET_IPV4_CONF_ARPFILTER,
	NET_IPV4_CONF_MEDIUM_ID,
	NET_IPV4_CONF_NOXFRM,
	NET_IPV4_CONF_NOPOLICY,
	NET_IPV4_CONF_FORCE_IGMP_VERSION,
	NET_IPV4_CONF_ARP_ANNOUNCE,
	NET_IPV4_CONF_ARP_IGNORE,
	NET_IPV4_CONF_PROMOTE_SECONDARIES,
	NET_IPV4_CONF_ARP_ACCEPT,
	NET_IPV4_CONF_ARP_NOTIFY,
	NET_IPV6_CONF,
	NET_IPV6_NEIGH,
	NET_IPV6_ROUTE,
	NET_IPV6_ICMP,
	NET_IPV6_BINDV6ONLY,
	NET_IPV6_IP6FRAG_HIGH_THRESH,
	NET_IPV6_IP6FRAG_LOW_THRESH,
	NET_IPV6_IP6FRAG_TIME,
	NET_IPV6_IP6FRAG_SECRET_INTERVAL,
	NET_IPV6_MLD_MAX_MSF,
	NET_IPV6_ROUTE_FLUSH,
	NET_IPV6_ROUTE_GC_THRESH,
	NET_IPV6_ROUTE_MAX_SIZE,
	NET_IPV6_ROUTE_GC_MIN_INTERVAL,
	NET_IPV6_ROUTE_GC_TIMEOUT,
	NET_IPV6_ROUTE_GC_INTERVAL,
	NET_IPV6_ROUTE_GC_ELASTICITY,
	NET_IPV6_ROUTE_MTU_EXPIRES,
	NET_IPV6_ROUTE_MIN_ADVMSS,
	NET_IPV6_ROUTE_GC_MIN_INTERVAL_MS,
	NET_UNIX_DESTROY_DELAY,
	NET_UNIX_DELETE_DELAY,
	NET_UNIX_MAX_DGRAM_QLEN,
	VM_OVERCOMMIT_MEMORY,
	VM_PAGE_CLUSTER,
	VM_DIRTY_BACKGROUND,
	VM_DIRTY_RATIO,
	VM_DIRTY_WB_CS,
	VM_DIRTY_EXPIRE_CS,
	VM_NR_PDFLUSH_THREADS,
	VM_OVERCOMMIT_RATIO,
	VM_PAGEBUF,
	VM_HUGETLB_PAGES,
	VM_SWAPPINESS,
	VM_LOWMEM_RESERVE_RATIO,
	VM_MIN_FREE_KBYTES,
	VM_MAX_MAP_COUNT,
	VM_LAPTOP_MODE,
	VM_BLOCK_DUMP,
	VM_HUGETLB_GROUP,
	VM_VFS_CACHE_PRESSURE,
	VM_LEGACY_VA_LAYOUT,
	VM_SWAP_TOKEN_TIMEOUT
]),,,
[#include <sys/types.h>
#include <linux/sysctl.h>])

AC_CHECK_DECLS(m4_normalize([
	V4L2_FIELD_ANY,
	V4L2_FIELD_NONE,
	V4L2_FIELD_TOP,
	V4L2_FIELD_BOTTOM,
	V4L2_FIELD_INTERLACED,
	V4L2_FIELD_SEQ_TB,
	V4L2_FIELD_SEQ_BT,
	V4L2_FIELD_ALTERNATE,
	V4L2_FIELD_INTERLACED_TB,
	V4L2_FIELD_INTERLACED_BT,
	V4L2_BUF_TYPE_VIDEO_CAPTURE,
	V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE,
	V4L2_BUF_TYPE_VIDEO_OUTPUT,
	V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE,
	V4L2_BUF_TYPE_VIDEO_OVERLAY,
	V4L2_BUF_TYPE_VBI_CAPTURE,
	V4L2_BUF_TYPE_VBI_OUTPUT,
	V4L2_BUF_TYPE_SLICED_VBI_CAPTURE,
	V4L2_BUF_TYPE_SLICED_VBI_OUTPUT,
	V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY,
	V4L2_TUNER_RADIO,
	V4L2_TUNER_ANALOG_TV,
	V4L2_TUNER_DIGITAL_TV,
	V4L2_MEMORY_MMAP,
	V4L2_MEMORY_USERPTR,
	V4L2_MEMORY_OVERLAY,
	V4L2_MEMORY_DMABUF,
	V4L2_COLORSPACE_SMPTE170M,
	V4L2_COLORSPACE_SMPTE240M,
	V4L2_COLORSPACE_REC709,
	V4L2_COLORSPACE_BT878,
	V4L2_COLORSPACE_470_SYSTEM_M,
	V4L2_COLORSPACE_470_SYSTEM_BG,
	V4L2_COLORSPACE_JPEG,
	V4L2_COLORSPACE_SRGB,
	V4L2_PRIORITY_UNSET,
	V4L2_PRIORITY_BACKGROUND,
	V4L2_PRIORITY_INTERACTIVE,
	V4L2_PRIORITY_RECORD,
	V4L2_FRMSIZE_TYPE_DISCRETE,
	V4L2_FRMSIZE_TYPE_CONTINUOUS,
	V4L2_FRMSIZE_TYPE_STEPWISE,
	V4L2_FRMIVAL_TYPE_DISCRETE,
	V4L2_FRMIVAL_TYPE_CONTINUOUS,
	V4L2_FRMIVAL_TYPE_STEPWISE,
	V4L2_CTRL_TYPE_INTEGER,
	V4L2_CTRL_TYPE_BOOLEAN,
	V4L2_CTRL_TYPE_MENU,
	V4L2_CTRL_TYPE_BUTTON,
	V4L2_CTRL_TYPE_INTEGER64,
	V4L2_CTRL_TYPE_CTRL_CLASS,
	V4L2_CTRL_TYPE_STRING,
	V4L2_CTRL_TYPE_BITMASK,
	V4L2_CTRL_TYPE_INTEGER_MENU
]),,, [#include <linux/videodev2.h>])

AC_CACHE_CHECK([for BLKGETSIZE64], [ac_cv_have_blkgetsize64],
	[AC_COMPILE_IFELSE([AC_LANG_PROGRAM([
#include <stdlib.h>
#include <linux/fs.h>], [return !BLKGETSIZE64;])],
			   [ac_cv_have_blkgetsize64=yes], [ac_cv_have_blkgetsize64=no])]
	if test $ac_cv_have_blkgetsize64 = yes; then
		AC_DEFINE([HAVE_BLKGETSIZE64], [1], [Define to 1 if you have BLKGETSIZE64.])
	fi)

AC_CHECK_SIZEOF([long])
AC_CHECK_SIZEOF([long long])
AC_CHECK_SIZEOF([off_t],,[#include <sys/types.h>])
AC_CHECK_SIZEOF([struct i64_i32],,[struct i64_i32 {long long i64; int i32;};])

AC_CACHE_CHECK([for SIGRTMIN], [st_cv_SIGRTMIN],
	       [[st_cv_SIGRTMIN="$(echo SIGRTMIN |
			$CPP $CPPFLAGS -P -imacros asm/signal.h - |
			grep '^[0-9]')"
	         test -n "$st_cv_SIGRTMIN" || st_cv_SIGRTMIN=no]])
if test "x$st_cv_SIGRTMIN" != xno; then
	AC_DEFINE_UNQUOTED([ASM_SIGRTMIN], [$st_cv_SIGRTMIN],
			   [SIGRTMIN defined in <asm/signal.h>])
fi
AC_CACHE_CHECK([for SA_RESTORER], [st_cv_SA_RESTORER],
	       [st_cv_SA_RESTORER="$(echo SA_RESTORER |
			$CPP $CPPFLAGS -P -imacros asm/signal.h - |
			grep ^0x)"
	        test -n "$st_cv_SA_RESTORER" || st_cv_SA_RESTORER=no])
if test "x$st_cv_SA_RESTORER" != xno; then
	AC_DEFINE_UNQUOTED([ASM_SA_RESTORER], [$st_cv_SA_RESTORER],
			   [SA_RESTORER defined in <asm/signal.h>])
fi

AC_CACHE_CHECK([for __builtin_popcount], [st_cv_have___builtin_popcount],
	       [AC_LINK_IFELSE([AC_LANG_PROGRAM([], [__builtin_popcount(0)])],
			       [st_cv_have___builtin_popcount=yes],
			       [st_cv_have___builtin_popcount=no])])
if test "x$st_cv_have___builtin_popcount" = xyes; then
	AC_DEFINE([HAVE___BUILTIN_POPCOUNT], [1],
		  [Define to 1 if the system provides __builtin_popcount function])
fi

AC_CHECK_LIB([dl], [dladdr], [dl_LIBS='-ldl'], [dl_LIBS=])
if test "x$ac_cv_lib_dl_dladdr" = xyes; then
	AC_DEFINE([HAVE_DLADDR], [1], [Define to 1 if the system provides dladdr])
fi
AC_SUBST(dl_LIBS)

AC_PATH_PROG([PERL], [perl])

dnl stack trace with libunwind
libunwind_CPPFLAGS=
libunwind_LDFLAGS=
libunwind_LIBS=
AC_ARG_WITH([libunwind],
            [AS_HELP_STRING([--with-libunwind],
                            [use libunwind to implement stack tracing support])],
            [case "${withval}" in
             yes|no|check) ;;
             *) with_libunwind=yes
                libunwind_CPPFLAGS="-I${withval}/include"
                libunwind_LDFLAGS="-L${withval}/lib" ;;
             esac],
            [with_libunwind=check]
)

use_libunwind=no
AS_IF([test "x$with_libunwind" != xno],
      [saved_CPPFLAGS="$CPPFLAGS"
       CPPFLAGS="$CPPFLAGS $libunwind_CPPFLAGS"

       AC_CHECK_HEADERS([libunwind-ptrace.h],
         [saved_LDFLAGS="$LDFLAGS"
          LDFLAGS="$LDFLAGS $libunwind_LDFLAGS"

          AC_CHECK_LIB([unwind], [backtrace],
            [libunwind_LIBS="-lunwind $libunwind_LIBS"

             AC_MSG_CHECKING([for unw_create_addr_space in libunwind-generic])
             saved_LIBS="$LIBS"
             LIBS="-lunwind-generic $libunwind_LIBS $LIBS"

             AC_LINK_IFELSE(
               [AC_LANG_PROGRAM([[#include <libunwind-ptrace.h>]],
                                [[return !unw_create_addr_space(0, 0)]])
               ],
               [AC_MSG_RESULT([yes])
                libunwind_LIBS="-lunwind-generic $libunwind_LIBS"

                AC_CHECK_LIB([unwind-ptrace], [_UPT_create],
                  [libunwind_LIBS="-lunwind-ptrace $libunwind_LIBS"
                   use_libunwind=yes
                  ],
                  [if test "x$with_libunwind" != xcheck; then
                     AC_MSG_FAILURE([failed to find _UPT_create in libunwind-ptrace])
                   fi
                  ],
                  [$libunwind_LIBS]
                )
               ],
               [AC_MSG_RESULT([no])
                if test "x$with_libunwind" != xcheck; then
                  AC_MSG_FAILURE([failed to find unw_create_addr_space in libunwind-generic])
                fi
               ]
             )

             LIBS="$saved_LIBS"
            ],
            [if test "x$with_libunwind" != xcheck; then
               AC_MSG_FAILURE([failed to find libunwind])
             fi
            ],
            [$libunwind_LIBS]
          )

          LDFLAGS="$saved_LDFLAGS"
         ],
         [if test "x$with_libunwind" != xcheck; then
            AC_MSG_FAILURE([failed to find libunwind-ptrace.h])
          fi
         ]
       )

       CPPFLAGS="$saved_CPPFLAGS"
      ]
)

dnl enable libunwind
AC_MSG_CHECKING([whether to enable stack tracing support using libunwind])
if test "x$use_libunwind" = xyes; then
	AC_DEFINE([USE_LIBUNWIND], 1, [Compile stack tracing functionality])
	AC_SUBST(libunwind_LIBS)
	AC_SUBST(libunwind_LDFLAGS)
	AC_SUBST(libunwind_CPPFLAGS)
fi
AM_CONDITIONAL([USE_LIBUNWIND], [test "x$use_libunwind" = xyes])
AC_MSG_RESULT([$use_libunwind])

if test "$arch" = mips && test "$no_create" != yes; then
	mkdir -p linux/mips
	if $srcdir/linux/mips/genstub.sh linux/mips; then
		AC_MSG_RESULT([Generated MIPS syscallent stubs])
	else
		AC_MSG_FAILURE([Failed to generate syscallent stubs])
	fi
fi

st_MPERS([m32], [aarch64|powerpc64|sparc64|tile|x32|x86_64])
st_MPERS([mx32], [x86_64])

AC_CONFIG_FILES([Makefile tests/Makefile tests-m32/Makefile tests-mx32/Makefile])
AC_OUTPUT
