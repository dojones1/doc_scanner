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

# ##########################

MY_DOC_SCANNER_UT_SRC = main_test.cpp
MY_DOC_SCANNER_UT_OBJECTS = $(UTOBJDIR)/main_test.o
MY_DOC_SCANNER_UT_INCLUDES = 

$(eval $(call MAKE_OSX_UT,doc_scanner_ut,DOC_SCANNER_UT, $(MY_DOC_SCANNER_UT_SRC),$(MY_DOC_SCANNER_UT_OBJECTS),))

###########################

all: $(ALL_BINS)

alltests: $(ALL_TESTS)

testrun: $(ALL_TESTS_RUN)

install: all
	@echo you must be root to install

clean: $(ALL_CLEANS)
