# Makefile for Linsched
# Not yet integrated with Kbuild
#

KBUILD_DEFCONFIG := defconfig
KBUILD_CFLAGS += -D__LINSCHED__ -O0

LINUXDIR := ../..

HEADER_ARCH := linsched

TIME_HDR := ${LINUXDIR}/kernel/timeconst.h

quiet_cmd_timeconst = GEN	  $@
cmd_timeconst = ${PERL} $< 1000 > $@

${obj}/${TIME_HDR}:	${src}/${LINUXDIR}/kernel/timeconst.pl FORCE
	$(call if_changed,timeconst)

${obj}/${LINUXDIR}/kernel/time.o: ${obj}/${TIME_HDR}

targets += ${TIME_HDR}

obj-y +=	${LINUXDIR}/kernel/notifier.o
obj-y +=	${LINUXDIR}/kernel/timer.o
obj-y +=	${LINUXDIR}/kernel/time/clockevents.o
obj-y +=	${LINUXDIR}/kernel/sched/clock.o
obj-y +=	${LINUXDIR}/kernel/sched/core.o
obj-y +=	${LINUXDIR}/kernel/sched/cpupri.o
obj-y +=	${LINUXDIR}/kernel/sched/debug.o
obj-y +=	${LINUXDIR}/kernel/sched/idle_task.o
obj-y +=	${LINUXDIR}/kernel/sched/fair.o
obj-y +=	${LINUXDIR}/kernel/sched/rt.o
obj-y +=	${LINUXDIR}/kernel/sched/stats.o
obj-y +=	${LINUXDIR}/kernel/sched/stop_task.o
obj-y +=	${LINUXDIR}/kernel/fork.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/init_task.o
obj-y +=	${LINUXDIR}/kernel/exit.o ${LINUXDIR}/kernel/time.o
obj-y +=	${LINUXDIR}/kernel/cpu.o
obj-y +=	${LINUXDIR}/kernel/rwsem.o
obj-y +=	${LINUXDIR}/kernel/mutex.o
obj-y +=	${LINUXDIR}/kernel/hrtimer.o
obj-y +=	${LINUXDIR}/kernel/pid.o
obj-y +=	${LINUXDIR}/kernel/posix-cpu-timers.o
obj-y +=	${LINUXDIR}/kernel/spinlock.o
obj-y +=	${LINUXDIR}/kernel/time/timekeeping.o
obj-y +=	${LINUXDIR}/kernel/time/ntp.o
obj-y +=	${LINUXDIR}/kernel/time/jiffies.o
obj-y +=	${LINUXDIR}/kernel/time/tick-common.o
obj-y +=	${LINUXDIR}/kernel/time/tick-oneshot.o
obj-y +=	${LINUXDIR}/kernel/time/tick-sched.o
obj-y +=	${LINUXDIR}/kernel/time/tick-broadcast.o
obj-y +=	${LINUXDIR}/kernel/wait.o
obj-y +=	${LINUXDIR}/arch/linsched/init.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/process.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/smp.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/pid.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/mm.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/io.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/fs.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/ns.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/rcu.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/irq.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/version.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/percpu.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/lock.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/cred.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/cgroup.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/capability.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/misc.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/sched.o
obj-y +=	${LINUXDIR}/arch/linsched/kernel/user.o
obj-y +=	${LINUXDIR}/lib/rbtree.o ${LINUXDIR}/lib/div64.o
obj-y +=	${LINUXDIR}/lib/cpumask.o ${LINUXDIR}/lib/bitmap.o
obj-y +=	${LINUXDIR}/lib/list_debug.o
obj-y +=	${LINUXDIR}/lib/find_next_bit.o
obj-y +=	${LINUXDIR}/lib/hweight.o ${LINUXDIR}/lib/reciprocal_div.o
obj-y +=	${LINUXDIR}/lib/plist.o
obj-y +=	${LINUXDIR}/lib/ctype.o ${LINUXDIR}/lib/string.o
obj-y +=	${LINUXDIR}/lib/hexdump.o ${LINUXDIR}/lib/percpu_counter.o
obj-y +=	${LINUXDIR}/lib/timerqueue.o
obj-y +=	${LINUXDIR}/lib/find_last_bit.o
obj-y +=	${LINUXDIR}/lib/flex_array.o
obj-y +=	${LINUXDIR}/lib/rwsem-spinlock.o
obj-y +=	${LINUXDIR}/lib/kstrtox.o
obj-y +=	${LINUXDIR}/lib/idr.o

extra-y :=	${LINUXDIR}/kernel/time.o

all: ${TIME_HDR}
