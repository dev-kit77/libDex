#ifndef LIBRARY_H
#define LIBRARY_H

#include "publication.h"
#include "member.h"
#include "sortedList.h"

#include <string>

class Library {
    public:
        Library() = delete;
        ~Library();

        static Publication* getPublication(const std::string pubID);
    private:
        static SortedList<Publication, std::string> publications;
};

#endif
