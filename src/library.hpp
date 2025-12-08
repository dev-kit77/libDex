//header includes
#include "codes.h"
#include "library.h"
#include "loan.h"
#include "sortedList.hpp"
#include "util.hpp"

//standard library includes
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <list>
#include <ostream>
#include <sstream>
#include <string>

template<class T>
int Library::add(T& data) {
    //store list for easy access
    auto* l = this->getList(*data);

    //loop for length of the list
    for (int i = 0; i < l->size(); i++) {
        //check if current index holds needed id
        if (data->getID() == l->get(i)->getID()) {
            //return status code
            return ELEMENT_ALREADY_EXISTS;
        }
    }

    //insert to list
    return l->insert(*data);
}

template<class T>
int Library::remove(T& data) {
    return this->getList(*data)->remove(*data);
}

template<class T>
int Library::clean() {
    //store list for easy access
    auto* l = this->getList(*new T);

    //loop for length of the list
    for (int i = 0; i < l->size() - 1; i++) {
        T* current = l->get(i);
        //check if current index holds needed id
        while (l->get(i+1) != NULL) {
            //check for duplicate
            if (current->getID() == l->get(i+1)->getID()) {
                //remove dupilicate
                l->remove(*l->get(i+1));
            }
            else {
                //no duplicate exit checking loop
                break;
            }
        }
    }

    //return status code
    return ELEMENT_UPDATED;
}

template<class T>
std::string Library::format() const {
    //store list for easy access
    auto* l = this->getList(*new T);

    //init stringstream
    std::stringstream* ss = new std::stringstream();

    //loop for all indexes
    for (int i = 0; i < l->size(); i++) {
        if (i == 0) {
            *ss << std::to_string(i + 1) << ". " << *l->get(i);
        }
        else {
            *ss << "\n" << std::to_string(i + 1) << ". " << *l->get(i);
        }
    }

    //return string
    return ss->str();
}

template<class T>
T* Library::search(const std::string& searchTerm) const {
    return this->getList(*new T)->findNearest(searchTerm);
}

template<class T>
Publication* Library::findPublication(const std::string& id) const {
    //store list for easy access
    auto* l = this->getList(*new T);

    //loop for all indexes
    for (int i = 0; i < l->size(); i++) {
        //get current index
        T* found = l->get(i);

        //check if node is search node
        if (found->getID() == id) {
            //return node
            return found;
        }
    }

    return nullptr;
}

template<class T>
T* Library::advancedSearch(const std::string& keystring, std::string (T::*getter)() const) const {
    //store list for easy access
    auto* l = this->getList(*new T);

    //init lowest to store closest match
    int lowest = 99999999;

    //init pointer to result
    T* result = nullptr;

    //get keywords
    std::list<std::string*>* keywords = util::getKeywords(keystring);

    //loop for all indexes
    for (int i = 0; i < l->size(); i++) {
        //init total
        int total = 0;
        int average = 0;

        //get keywords
        std::list<std::string*>* searchwords = util::getKeywords((*l->get(i).*getter)());

        //loop for all keywords
        for (std::string* keyword : *keywords) {
            //copy search words for this keyword
            std::list<std::string*> currwords = *searchwords;

            //find ? wildcard
            int i = keyword->find('?');

            //loop until none found
            while (i != -1) {
                //remove ? at index
                keyword->erase(keyword->begin() + i);

                //loop for all search words
                for (std::string* searchword : currwords) {
                    //check if found index is greater than length of string
                    if (i < searchword->length()) {
                        //remove char at index
                        searchword->erase(searchword->begin() + i);
                    }
                }

                //check for new ?
                i = keyword->find('?');
            }

            //find * wildcard
            i = keyword->find('*');

            //take substring of everything before *
            *keyword = keyword->substr(0, i-1);

            //loop for all searchwords
            for (std::string* searchword : currwords) {
                //check if found index is greater than length of string
                if (i < searchword->length()) {
                    //take substring of everything before *
                    *searchword = searchword->substr(0, i-1);
                }
            }

            //loop for all searchwords
            for (std::string* searchword : currwords) {
                //trigger levenshtien recoursion and get result
                total += util::levenshtein(*keyword, *searchword, keyword->length(), searchword->length());
            }
        }

        //divide total by search terms
        average = (total / searchwords->size());

        //check if this is best match
        if (average < lowest) {
            //set new lowest
            lowest = average;

            //update result pointer
            result = l->get(i);
        }
    }

    //return search result
    return result;
}

template<class dataType, typename searchType>
int Library::writeLoans(SortedList<dataType, searchType>& p, std::ostream& os) {
    //loop for all publications
    for (int i = 0; i < p.size(); i++) {
        //get loans from publication
        std::list<Loan*>* loans = p.get(i)->getLoans();

        //loop for all loans
        for (Loan* l : *loans) {
            //output loan to filestream
            os << l->getMember()->getID() << " " << l->getPublication()->getID() << " " << l->getActive() << " " << l->getDue() << std::endl;

            //check for writing errors
            if (os.fail() || os.bad()) {
                //return status code
                return FILE_ERROR;
            }
        }
    }

    //return status code
    return FILE_WRITTEN;
}
