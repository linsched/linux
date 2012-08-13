CC = ${CROSS_COMPILE}gcc

CFLAGS = -g -O2 -m64 -D__KERNEL__ -D__LINSCHED__ -Wall -Wundef -Wstrict-prototypes \
	 -Werror-implicit-function-declaration -fno-common \
	 -I${LINSCHED_DIR}/include  -I${LINUXDIR}/include \
	 -I${LINUXDIR}/arch/linsched/include -I${LINSCHED_DIR}\
	 -Wno-pointer-sign -include ${LINUXDIR}/include/linux/kconfig.h

# Don't use system headers (such as /usr/include/asm) for the kernel
CFLAGS_LINUX = $(CFLAGS) -nostdinc -isystem $(shell $(CC) -print-file-name=include) \
	       -include ${LINSCHED_DIR}/linux_linsched.h \
	       -Wno-unused  -Wno-strict-aliasing

LFLAGS = -lm

LINSCHED_OBJS = ${LINSCHED_DIR}/linux_linsched.o \
		${LINSCHED_DIR}/numa.o \
		${LINSCHED_DIR}/hrtimer.o \
		${LINSCHED_DIR}/stubs.o \
		${LINSCHED_DIR}/test_lib.o \
		${LINSCHED_DIR}/linsched.o \
		${LINSCHED_DIR}/load_balance_score.o \
		${LINSCHED_DIR}/sanity_check.o \
		${LINSCHED_DIR}/nohz_tracking.o \
		${LINSCHED_DIR}/linsched_rand.o \
		${LINSCHED_DIR}/linsched_sim.o

LD_PERCPU = ${LD} -r -T ${LINSCHED_DIR}/linsched.lds

LINSCHED_ARCH = ${LINUXDIR}/arch/linsched/
LINUX_OBJS_DIR = ${LINSCHED_DIR}/bin
LINUX_OBJS=${LINSCHED_ARCH}/built-in.o


${LINUX_OBJS}:
	@echo "(Generating kernel)"
	${MAKE} --directory=${LINUXDIR}/ ARCH=linsched arch/linsched/

OBJ_FILES = ${LINSCHED_OBJS} ${LINUX_OBJS}

TIME_HDR=${LINUXDIR}/kernel/timeconst.h
${TIME_HDR}: ${LINUXDIR}/kernel/timeconst.pl
	@echo "(Generating timeconst.h)"
	@perl $< 1000 > $@
%.o: ${TIME_HDR}

%.o: %.c ${TIME_HDR}
	@echo "CC SIM $<"
	@${CC} ${CFLAGS} -o $@ -c $< -MMD
