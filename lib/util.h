#ifndef UTIL_H
#define UTIL_H

//standard library includes
#include <string>
#include <istream>

namespace util {
    /**
    * Method to parse input from a quoted string from the given input stream.
    *
    * @param is: The input stream to parse from.
    *
    * @return The parsed input as string.
    */
    std::string parseStringInput(std::istream& is);

    /**
    * Method to parse input of a type from the given input stream.
    *
    * @param is: The input stream to parse from.
    *
    * @return The parsed input, as type.
    */
    template<typename T>
    T parse(std::istream& is);
}

#endif // UTIL_H
