LINUXDIR = ./../..
LINSCHED_DIR=${LINUXDIR}/tools/linsched
include Makefile.inc

TEST_LIB = test_lib.o

.PHONY: run_all_tests all config
.DEFAULT_GOAL := all

#We always want to generate a .config, so make it a phony target
config:
	@echo "(Generating kernel config)"
	${MAKE} --directory=${LINUXDIR}/ ARCH=linsched defconfig

all:  config ${TEST_LIB} ${OBJ_FILES}
	$(MAKE) $(MFLAGS) --directory=tests all
	$(MAKE) $(MFLAGS) --directory=validation all

run_unit_tests: all
	$(MAKE) $(MFLAGS) --directory=tests run_unit_tests

run_all_tests: all
	$(MAKE) $(MFLAGS) --directory=tests run_all_tests

clean:
	rm -f ${TESTS} ${OBJ_FILES} ${GEN_HDR} ${TIME_HDR}
	$(MAKE) $(MFLAGS) --directory=tests clean
	${MAKE} --directory=${LINUXDIR} ARCH=linsched mrproper
