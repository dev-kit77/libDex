//header include
#include "util.h"
#include "util.hpp"

//standard library includes
#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

std::string util::parseStringInput(std::istream& is) {
    //init parcing string
    char* str = new char[256];

    //look for opening quote
    while (is.peek() != '\"') {
        //ignore characters until quote is found
        is.ignore();

        //check for end of file
        if (is.eof()) {
            delete[] str;
            return "";
        }
    }

    //consume opening quote
    is.ignore();

    //read input from stream
    is.get(str, 256, '\"');

    //consume closing quote
    is.ignore();

    //return input
    return str;
}

int util::levenshtein(const std::string& s1, const std::string& s2, int l1, int l2) {
    //check for full diference
    if (l1 == 0) {
        return l2;
    }
    else if (l2 == 0) {
        return l1;
    }
    //if strings are same with one letter removed
    else if (s1[l1 - 1] == s2[l2 - 1]) {
        //reccoursive call with cut lengths
        return levenshtein(s1, s2, l1 - 1, l2 - 1);
    }

    //calculate insertion/removal/replacement taking the minimum levenshtien distance between strings
    return 1 + std::min(levenshtein(s1, s2, l1, l2 - 1), std::min(levenshtein(s1, s2, l1 - 1, l2), levenshtein(s1, s2, l1 - 1, l2- 1)));
}

std::list<std::string>* util::getKeywords(const std::string& keystring) {
    //get stringstream from keystring
    std::stringstream* keystream = new std::stringstream(keystring);

    //init keyword list
    std::list<std::string>* keywords = new std::list<std::string>();

    //init temp string
    std::string t;

    //loop until searchstring is exausted
    while (keystream->good()) {
        //read in value
        *keystream >> t;

        //remove any stray commas
        t.erase(std::remove(t.begin(), t.end(), ','), t.end());

        //add to search words
        keywords->push_back(t);
    }

    //return list of words
    return keywords;
}
