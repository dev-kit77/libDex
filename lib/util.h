#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <istream>

namespace util {
    /**
    * Method to parse input from a quoted string from the given input stream.
    *
    * @param is: The input stream to parse.
    *
    * @return The parsed input as string.
    */
    std::string parseStringInput(std::istream& is);
}

#endif // UTIL_H
