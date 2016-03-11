DOC_SCANNERP_CPP_SRC = $(wildcard $(DOC_SCANNERP_DIR)/*.cpp)
DOC_SCANNERP_INCLUDES = -I$(SCANNEDDOC_DIR)


# 1 is the name of the make file target
# 2 is the name of the binary
# 3 is the list of c files
# 4 is the c flags
# 5 is the list of c++ files
# 6 is the c++ flags
$(eval $(call OSX_BIN, doc_scannerp_bin,doc_scannerp,,,$(DOC_SCANNERP_CPP_SRC),$(DOC_SCANNERP_INCLUDES)))