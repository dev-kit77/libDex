#include "util.h"

#include <iostream>
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

template<typename T>
T util::parse(std::istream& is) {
    //init auto for input
    T ipt = new T();

    //check for early new line or EOF
    if (is.peek() != '\n' && is.peek() != EOF) {
        //read data
        is >> ipt;
    }
    else {
        //set failbit to indicate read error of early new line
        is.setstate(std::ios::failbit);
    }

    //return input
    return ipt;
}
