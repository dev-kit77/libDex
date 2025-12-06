#ifndef UTIL_H
#define UTIL_H

//standard library includes
#include <list>
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

    /**
     * Implementation of the levernshtein distance algorithm.
     *
     * @param s1 first string to compare.
     * @param s2 second string to compare.
     * @param l1 length of the first string
     * @param n length of the second string
     */
    int levenshtein(const std::string& s1, const std::string& s2, int l1, int l2);

    /**
     * Method to extract keywords from a string.
     * @param keystring the string to extract the keywords from
     * @return a list of keywords
     */
    std::list<std::string>* getKeywords(const std::string& keystring);
}

#endif // UTIL_H
