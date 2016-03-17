// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "ScannedDoc.h"
#include "gtest/gtest.h"

// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
// </TechnicalDetails>

string rootPath = "common/lib/ScannedDoc/unit_test/etc/";

TEST(DISABLED_falseTest, Negative) {
 EXPECT_FALSE(1);
}

TEST(falseTest, Positive) {
 EXPECT_FALSE(0);
}
TEST(DISABLED_trueTest, Negative) {
 EXPECT_TRUE(0);
}

TEST(trueTest, Positive) {
 EXPECT_TRUE(1);
}

/*test_file_info_s testFileInfo[] = {

//      filename     lines, words, letter, mfl
      { "test0.txt",     0,     0,      0, '\0'} // Empty file
    , { "test0a.txt",    3,     0,      0, '\0'}
    , { "test1.txt",     1,     1,      5, 'l' }
    , { "test1a.txt",    1,     1,      5, 'l' }
    , { "test1b.txt",    1,     2,     12, 'o'}
    , { "test1c.txt",    1,     3,      7, 'b'}
    , { "test2.txt",    26,    26,     26, 'a'}
    , { "test3.txt",    26,    26,     27, 'n'}
    , { "test4.txt",     1,    26,     26, 'a'}
    , { "test5.txt",  3721, 21318,  85791, 'e'}
}
*/
TEST(scanned_doc_ut_0, Positive) {
	ScannedDoc doc(rootPath + "test0.txt");
    
    EXPECT_EQ(doc.getLineCount(), static_cast<const unsigned int>(0));
    EXPECT_EQ(doc.getWordCount(), static_cast<const unsigned int>(0));
    EXPECT_EQ(doc.getLetterCount(), static_cast<const unsigned int>(0));
    EXPECT_EQ(doc.getMostFreqLetter(), '\0');   
}

TEST(scanned_doc_ut_0a, Positive) {
	ScannedDoc doc(rootPath + "test0a.txt");
    
    EXPECT_EQ(doc.getLineCount(), static_cast<const unsigned int>(3));
    EXPECT_EQ(doc.getWordCount(), static_cast<const unsigned int>(0));
    EXPECT_EQ(doc.getLetterCount(), static_cast<const unsigned int>(0));
    EXPECT_EQ(doc.getMostFreqLetter(), '\0');   
}

TEST(scanned_doc_ut_1, Positive) {
	ScannedDoc doc(rootPath + "test1.txt");
    
    EXPECT_EQ(doc.getLineCount(), static_cast<const unsigned int>(1));
    EXPECT_EQ(doc.getWordCount(), static_cast<const unsigned int>(1));
    EXPECT_EQ(doc.getLetterCount(), static_cast<const unsigned int>(5));
    EXPECT_EQ(doc.getMostFreqLetter(), 'l');   
}

TEST(scanned_doc_ut_1a, Positive) {
	ScannedDoc doc(rootPath + "test1a.txt");
    
    EXPECT_EQ(doc.getLineCount(), static_cast<const unsigned int>(1));
    EXPECT_EQ(doc.getWordCount(), static_cast<const unsigned int>(1));
    EXPECT_EQ(doc.getLetterCount(), static_cast<const unsigned int>(5));
    EXPECT_EQ(doc.getMostFreqLetter(), 'l');   
}

TEST(scanned_doc_ut_1b, Positive) {
	ScannedDoc doc(rootPath + "test1b.txt");
    
    EXPECT_EQ(doc.getLineCount(), static_cast<const unsigned int>(1));
    EXPECT_EQ(doc.getWordCount(), static_cast<const unsigned int>(2));
    EXPECT_EQ(doc.getLetterCount(), static_cast<const unsigned int>(12));
    EXPECT_EQ(doc.getMostFreqLetter(), 'o');   
}

TEST(scanned_doc_ut_1c, Positive) {
	ScannedDoc doc(rootPath + "test1c.txt");
    
    EXPECT_EQ(doc.getLineCount(), static_cast<const unsigned int>(1));
    EXPECT_EQ(doc.getWordCount(), static_cast<const unsigned int>(3));
    EXPECT_EQ(doc.getLetterCount(), static_cast<const unsigned int>(7));
    EXPECT_EQ(doc.getMostFreqLetter(), 'b');   
}

TEST(scanned_doc_ut_2, Positive) {
	ScannedDoc doc(rootPath + "test2.txt");
    
    EXPECT_EQ(doc.getLineCount(), static_cast<const unsigned int>(26));
    EXPECT_EQ(doc.getWordCount(), static_cast<const unsigned int>(26));
    EXPECT_EQ(doc.getLetterCount(), static_cast<const unsigned int>(26));
    EXPECT_EQ(doc.getMostFreqLetter(), 'a');   
}

TEST(scanned_doc_ut_3, Positive) {
	ScannedDoc doc(rootPath + "test3.txt");
    
    EXPECT_EQ(doc.getLineCount(), static_cast<const unsigned int>(26));
    EXPECT_EQ(doc.getWordCount(), static_cast<const unsigned int>(26));
    EXPECT_EQ(doc.getLetterCount(), static_cast<const unsigned int>(27));
    EXPECT_EQ(doc.getMostFreqLetter(), 'n');   
}

TEST(scanned_doc_ut_4, Positive) {
	ScannedDoc doc(rootPath + "test4.txt");
    
    EXPECT_EQ(doc.getLineCount(), static_cast<const unsigned int>(1));
    EXPECT_EQ(doc.getWordCount(), static_cast<const unsigned int>(26));
    EXPECT_EQ(doc.getLetterCount(), static_cast<const unsigned int>(26));
    EXPECT_EQ(doc.getMostFreqLetter(), 'a');   
}

TEST(scanned_doc_ut_5, Positive) {
	ScannedDoc doc(rootPath + "test5.txt");
    
    EXPECT_EQ(doc.getLineCount(), static_cast<const unsigned int>(3721));
    EXPECT_EQ(doc.getWordCount(), static_cast<const unsigned int>(21318));
    EXPECT_EQ(doc.getLetterCount(), static_cast<const unsigned int>(85791));
    EXPECT_EQ(doc.getMostFreqLetter(), 'e');   
}

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?
