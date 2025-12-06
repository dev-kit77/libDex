#include "interface.h"
#include "util.h"
#include "util.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << std::to_string(util::levenshtein("kitten", "sitting", 6, 7)) << std::endl;

    for (std::string w : *util::getKeywords("Testing, Rockets")) {
        std::cout << w << std::endl;
    }

    //exit program
    return 0;
}
