SCANNED_DOC_UT_CPP_SRC = $(wildcard $(SCANNEDDOC_DIR)/unit_test/*.cpp)
SCANNED_DOC_UT_CPP_FLAGS = -I$(SCANNEDDOC_DIR)

$(eval $(call OSX_UT,osx_scanned_doc_ut,scanned_doc_ut,,,$(SCANNED_DOC_UT_CPP_SRC),$(SCANNED_DOC_UT_CPP_FLAGS)))