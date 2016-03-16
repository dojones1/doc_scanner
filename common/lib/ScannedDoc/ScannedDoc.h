//
//  ScannedDoc.hpp
//  doc_scanner
//
//  Created by Donald Jones on 13/11/2015.
//  Copyright © 2015 Donald Jones. All rights reserved.
//

#ifndef ScannedDoc_hpp
#define ScannedDoc_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

class ScannedDoc {
    string m_filename;      ///< File name
    ifstream m_ifs;         ///< File stream
    
    unsigned int m_word_count; 		///< Count of whitespace delimited words are present
    unsigned int m_line_count;		///< Count of lines in file
    unsigned int m_letter_count;	///< Number of letters found in the file: a-z, A-Z
    char m_most_freq_letter;		///< Calculated most frequent letter.  
    vector<unsigned int> m_letter_freq;


public:
    ScannedDoc(std::string filename):
        m_word_count(0),
        m_line_count(0),
        m_letter_count(0),
        m_most_freq_letter('\0')
    {
        m_filename.assign(filename);
        m_letter_freq.assign(26, 0);
        
        
        // Process the file itself
        m_ifs.open(m_filename);
        if (! m_ifs.is_open())
        {
            throw runtime_error( "Could not open file" );
        }
        
        string line;
        while (getline(m_ifs, line))
        {
            parseLine(line);
        }
        
        // File parsed so do any appropriate post-processing.
        doFreqAnalysis();
        
        m_ifs.close();
    }
    
// **********************
// Stats Accessor methods
// **********************
    unsigned int getWordCount()   { return m_word_count; };
    unsigned int getLineCount()   { return m_line_count; };
    unsigned int getLetterCount() { return m_letter_count; };
    
    //! Calculates the average word length
    /*!
    	This will return zero in the case of no words being counted
     */ 
    double getAvgWordLength()
    {
        if (m_word_count == 0) return 0; // Handle div by 0 case;
        
        return ((double)m_letter_count / m_word_count);
    };
    
    //! Returns letter with the highest frequency.
    /*!
    	Returns letter with the highest frequency. If two characters have the same frequency, 
    	then the alphabetically first letter will be returned
    */
    char getMostFreqLetter() { return m_most_freq_letter; };
    
    
// **************************
// Private Processing methods
// **************************
private:
	// Note: will ignore any non-letter characters from metrics
    void parseChar(char chr)
    {
        //cout << "in parseChar( " << chr << " )" << endl;
        
        // Convert upper case character to a lower case character
        if (chr >= 'A' && chr <= 'Z') { chr = tolower(chr); }
        
        // Do we have a valid letter?
        if (chr >= 'a' && chr <= 'z')
        {
            // Yes! Update stats
            m_letter_count++;
            m_letter_freq[chr -'a']++;
        }
    }
    
    
    void parseWord(string word)
    {
        //cout << "in parseWord( " << word << " )" << endl;

        // If this is a non-zero length word then increment the word count
        // Note this could count non-text only words.
        if (word.length())
        {
            m_word_count++;
            
            for (char& c : word)
            {
                parseChar(c);
            }
        }
        
    }
    
    void parseLine(string line)
    {
        //cout << "in parseLine( " << line << " )" << endl;
        
        m_line_count++;
        istringstream iss(line);
        
        do {
            string word;
            iss >> word;
            parseWord(word);
        } while (iss);
    }
    
    // Once the frequency count has been gathered, now can iterate over the list and identify most frequent
    void doFreqAnalysis()
    {
        m_most_freq_letter = '\0';
        unsigned int most_freq_letter_count = 0;
        for (vector<unsigned int>::iterator it = m_letter_freq.begin(); it != m_letter_freq.end(); ++it)
        {
            if (*it) // Only output non-zero values
            {
                unsigned long index = it - m_letter_freq.begin();
                char letter = index + 'a';

                // Was this the most frequent letter?
                if (*it > most_freq_letter_count)
                {
                    // Then record this
                    most_freq_letter_count = *it;
                    m_most_freq_letter = letter;
                }

            }
        }
    }
    
    // *************************
    // Public Processing methods
    // *************************
public:
    // Output all of the key parameters from the analysis
    void dumpStats()
    {
        cout.precision(1); // Only allow one decimal place precision.
        
        // Output Word count
        cout << "Word Count: " << m_word_count << endl;
        
        // Output line count
        cout << "Line Count: " << m_line_count << endl;
        
        // Total letter count
        cout << "Letter Count: " << m_letter_count << endl;
        
        // average number of letters per word (to one decimal place)
        cout << "Average Letters per word: " << fixed << getAvgWordLength() << endl;
        
        // Frequency distribution (and find most frequence letter)
        cout << "The Frequency Distribution is:" << endl;
        for (vector<unsigned int>::iterator it = m_letter_freq.begin(); it != m_letter_freq.end(); ++it)
        {
            if (*it) // Only output non-zero values
            {
                unsigned long index = it - m_letter_freq.begin();
                char letter = index + 'a';
                cout << '\t';
                cout << letter;
                cout << " : " << *it;
                
                cout << endl;
            }
        }
        cout << endl;
        
        // Most common Letter
        cout << "Most Frequent Letter: " << m_most_freq_letter << endl;
    }
};

#endif /* ScannedDoc_hpp */
