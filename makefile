include build/makefile.rules


##########################
# Pull in build targets from the system
# Thirdparty libraries first
include $(THIRDPARTY_DIR)/makefile.inc
include $(COMMON_LIB_DIR)/makefile.inc
include $(PROCESS_DIR)/makefile.inc


###########################

software: $(ALL_BINS)

alltests: $(ALL_TESTS)

test: $(ALL_TESTS_RUN)

all: software test

install: all
	@echo you must be root to install

clean: $(ALL_CLEANS)
