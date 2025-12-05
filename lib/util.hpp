//header include
#include "util.h"

//standard library includes
#include <cstdio>
#include <iostream>

namespace util {
    template<typename T>
    T parse(std::istream& is) {
        //init auto for input
        T* ipt = new T();

        //check for early new line or EOF
        if (is.peek() != '\n' && is.peek() != EOF) {
            //read data
            is >> *ipt;
        }
        else {
            //set failbit to indicate read error of early new line
            is.setstate(std::ios::failbit);
        }

        //return input
        return *ipt;
    }
}
