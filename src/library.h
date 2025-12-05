#ifndef LIBRARY_H
#define LIBRARY_H

//header includes
#include "publication.h"
#include "member.h"
#include "sortedList.h"

//standard library includes
#include <string>

class Library {
    public:
        Library();
        ~Library();

        Publication* getPublication(const std::string pubID);
    private:
        SortedList<Publication, std::string> publications;
};

#endif
