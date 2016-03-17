SCANNED_DOC_UT_GT_CPP_SRC = $(wildcard $(SCANNEDDOC_DIR)/unit_test_gt/*.cpp)
SCANNED_DOC_UT_GT_CPP_FLAGS = -I$(SCANNEDDOC_DIR) -I$(GTEST_DIR)/include

$(eval $(call OSX_UT,scanned_doc_ut_gt,SCANNED_DOC_UT_GT,,,$(SCANNED_DOC_UT_GT_CPP_SRC),$(SCANNED_DOC_UT_GT_CPP_FLAGS)))


# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

# sample1.o : $(USER_DIR)/sample1.cc $(USER_DIR)/sample1.h $(GTEST_HEADERS)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1.cc

# sample1_unittest.o : $(USER_DIR)/sample1_unittest.cc \
#                      $(USER_DIR)/sample1.h $(GTEST_HEADERS)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1_unittest.cc

# sample1_unittest : sample1.o sample1_unittest.o gtest_main.a
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@