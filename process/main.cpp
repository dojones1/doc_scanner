//
//  main.cpp
//  doc_scanner
//
//  Created by Donald Jones on 13/11/2015.
//  Copyright © 2015 Donald Jones. All rights reserved.
//

#include <iostream>
#include "ScannedDoc.hpp"

using namespace std;

extern void doTestFiles(); // see testFiles.cpp

void doFile(string filename)
{
    cout << "File: " << filename << endl;
    ScannedDoc doc(filename);
    doc.dumpStats();
    cout << endl;
}


int main(int argc, const char * argv[])
{
    cout << "Executable " << argv[0] << "\n";

    // Check that correct number of arguments provided
    if (argc != 2)
    {
        cout << "Usage is -in <infile>" << endl;
        exit(0);
    }

	try {
    	doFile(argv[1]);
	}
	catch (exception& e)
	{
		cout << "Exception caught: " << e.what() << endl;
	}
    return 0;
}
