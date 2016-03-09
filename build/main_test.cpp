//
//  testFiles.cpp
//  doc_scanner
//
//  Created by Donald Jones on 14/11/2015.
//  Copyright © 2015 Donald Jones. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "ScannedDoc.h"
#include <stdexcept>

struct test_file_info_s {
    string filename;
    unsigned int line_count;
    unsigned int word_count;
    unsigned int letter_count;
    char most_freq_letter;
};

// testFileInfo contains the test vectors used during development and the expected test results for those files
test_file_info_s testFileInfo[] = {
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
};

void doTestFile(test_file_info_s tf)
{
    string rootPath = "/Users/donaldjones/Documents/xcode projects/trackMix/Oracle DocScanner/doc_scanner/doc_scanner/";
    
    string filename = rootPath + tf.filename;
    cout << "File: " << filename << endl;
    ScannedDoc doc(filename);
    doc.dumpStats();
    cout << endl;
    
    // Validate the parameters
    if (tf.word_count != doc.getWordCount())
    {
        cout << "Wc: " << tf.word_count << " != " << doc.getWordCount() << endl;
        throw runtime_error( "word_count");
    }
    
    if (tf.line_count != doc.getLineCount())
    {
        cout << "Lc: " << tf.line_count << " != " << doc.getLineCount() << endl;
        throw runtime_error( "line_count");
    }
    
    if (tf.letter_count != doc.getLetterCount())
    {
        cout << "Wc: " << tf.letter_count << " != " << doc.getLetterCount() << endl;
        throw runtime_error( " letter_count");
    }

    if (tf.most_freq_letter != doc.getMostFreqLetter())
    {
        cout << "Wc: " << tf.most_freq_letter << " != " << doc.getMostFreqLetter() << endl;
        throw runtime_error( "most_freq_letter");
    }
}

int main(int argc, const char * argv[])
{
    vector<test_file_info_s> vTestFiles(testFileInfo, testFileInfo + sizeof(testFileInfo) / sizeof(testFileInfo[0]) );
    

    try {
   	   	// Process all test files
   	    for (vector<test_file_info_s>::iterator it = vTestFiles.begin(); it != vTestFiles.end(); ++it)
       	{
           	doTestFile(*it);
       	}
	}
	catch (exception& e)
	{
		cout << "Exception caught: " << e.what() << endl;
	}
    return 0;
}
