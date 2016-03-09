include makefile.rules


#Make the Directories
directories:
	$(_Q) $(MKDIR) $(OSXBINDIR) 
	$(_Q) $(MKDIR) $(OSXOBJDIR)
	$(_Q) $(MKDIR) $(UTBINDIR) 
	$(_Q) $(MKDIR) $(UTOBJDIR)

directories_clean:
	$(_Q) $(RMRF) $(OSXBINDIR) 
	$(_Q) $(RMRF) $(OSXOBJDIR)
	$(_Q) $(RMRF) $(OSXBUILDDIR)
	$(_Q) $(RMRF) $(UTBINDIR) 
	$(_Q) $(RMRF) $(UTOBJDIR)
	$(_Q) $(RMRF) $(UTBUILDDIR)

ALL_CLEANS += directories_clean

###########################
	
DOC_SCANNER_SRC = main.cpp
DOC_SCANNER_OBJECTS = $(OSXOBJDIR)/main.o
DOC_SCANNER_INCLUDES = 

doc_scanner: directories $(DOC_SCANNER_OBJECTS)
	@ echo "\033[0;35m [ OSX BIN:     $@ ] \033[m"
	$(_Q) $(CC) $(CPPFLAGS) $(DOC_SCANNER_INCLUDES) $(DOC_SCANNER_OBJECTS) -o $(OSXBINDIR)/$@

ALL_BINS += doc_scanner

doc_scanner_clean:
	$(_Q) $(RMF) $(OSXBINDIR)/doc_scanner
	
ALL_CLEANS += doc_scanner_clean

###########################

DOC_SCANNER_UT_SRC = main_test.cpp
DOC_SCANNER_UT_OBJECTS = $(UTOBJDIR)/main_test.o
DOC_SCANNER_UT_INCLUDES = 
doc_scanner_ut: directories $(DOC_SCANNER_UT_OBJECTS)
	@ echo "\033[0;36m [ OSX_UT_BIN:  $@ ] \033[m"
	$(_Q) $(CC) $(CPPFLAGS) $(DOC_SCANNER_UT_INCLUDES) $(DOC_SCANNER_UT_OBJECTS) -o $(UTBINDIR)/$@

ALL_BINS  += doc_scanner_ut
ALL_TESTS += doc_scanner_ut

doc_scanner_ut_run: doc_scanner_ut
	$(UTBINDIR)/doc_scanner_ut

ALL_TESTS_RUN += doc_scanner_ut_run	

doc_scanner_ut_clean:
	$(_Q) $(RMF) $(UTBINDIR)/doc_scanner_ut

ALL_CLEANS += doc_scanner_ut_clean;

all: $(ALL_BINS)

###########################


alltests: $(ALL_TESTS)

testrun: $(ALL_TESTS_RUN)

install: all
	@echo you must be root to install

clean: $(ALL_CLEANS)
