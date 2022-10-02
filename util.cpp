#include "util.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>

using namespace std;
std::string convToLower(std::string src) {
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords) {
    set<string> listKey;
    string words; 
    rawWords = convToLower(rawWords); 
    // turning punctuation to spaces 
    for (unsigned int i = 0; i < rawWords.size(); i++) {
        if (ispunct(rawWords[i]) ) {
            rawWords[i] = ' '; 
        }
    }
    // using string stream to read the rawWords (which eliminates the spaces )
    stringstream s (rawWords); 
    while (s >>words) {
        if (words.size() >= 2) {
            // only adding the word is the size of the string is 2 or more
            listKey.insert(words); 
        }
    }
    return listKey; 
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string& ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string& rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
std::string& trim(std::string& s) { return ltrim(rtrim(s)); }
