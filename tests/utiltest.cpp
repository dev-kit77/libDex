#include "interface.h"
#include "util.h"
#include "util.hpp"
#include <iostream>
#include <string>

int main() {
    //txt print
    interface::printTXT("./res/libdex.txt");

    //print separator
    interface::separator();

    //test message print
    interface::printMessage("Welcome to the Utilities Test!");

    //print separator
    interface::separator();

    //print message
    interface::printMessage("Levenshtein Algorithm Test 'kitten' & 'sitting':");
    std::cout << std::to_string(util::levenshtein("kitten", "sitting", 6, 7)) << std::endl;

    //newline
    interface::newLine();

    //print message
    interface::printMessage("Testing keyword extraction from string:");
    interface::printMessage("Testing, Rockets bites KFC hungry,");
    for (std::string w : *util::getKeywords("Testing, Rockets bites KFC hungry,")) {
        std::cout << w << std::endl;
    }

    //exit program
    return 0;
}
