//header guard
#ifndef SORTED_LIST_HPP
#define SORTED_LIST_HPP

//header includes
#include "sortedList.h"
#include "codes.h"

//standard library includes
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

template<class dataType, typename searchType>
inline SortedList<dataType, searchType>::SortedList() {
    //init head to null pointer
    head = nullptr;
}

template<class dataType, typename searchType>
inline SortedList<dataType, searchType>::~SortedList() {
    //init search nodes
    Node<dataType>* currNode = head;
    Node<dataType>* nextNode = nullptr;

    //loop through list until end
    while (currNode != nullptr) {
        //set next node pointer
        nextNode = currNode->getNext();

        //delete current node
        delete currNode;

        //update search nodes
        currNode = nextNode;
    }
}

template<class dataType, typename searchType>
inline int SortedList<dataType, searchType>::insert(dataType& value) {
    //init search nodes
    Node<dataType>* currNode = head;
    Node<dataType>* prevNode = nullptr;
    Node<dataType>* insertionNode = nullptr;

    //loop through list until end
    while (currNode != nullptr) {
        //check for duplicate entry
        if (&value == currNode->getPointer()) {
            //return status code for duplicate entry
            return ELEMENT_ALREADY_EXISTS;
        }
        //check if insertion point is null or current node is not head
        else if (insertionNode == nullptr && currNode != head) {
            //check if new node is between current and previous nodes
            if (currNode->getData() > value && prevNode->getData() < value) {
                //set insertion node to previous node
                insertionNode = prevNode;
            }
        }

        //check to see if current node should be insertion point
        if (currNode->getData() == value) {
            //set insertion node to current node
            insertionNode = currNode;
        }

        //update search nodes
        prevNode = currNode;
        currNode = currNode->getNext();
    }

    //check if insertion node is null
    if (insertionNode == nullptr) {
        //set insertion node to previous node as current node must at end of list
        insertionNode = prevNode;
    }

    //create new node
    Node<dataType>* newNode = new Node<dataType>(&value);

    //check if list is empty
    if (head == nullptr) {
        head = newNode;
        return ELEMENT_ADDED;
    }
    //check if new node is before head
    else if (head->getData() > value) {
        //set new node's next pointer to current head
        newNode->setNext(head);
        //set head pointer to new node
        head = newNode;

        //return status code
        return ELEMENT_ADDED;
    }
    //new node is between 2 nodes
    else {
        //set new node's next pointer to insertion node's next pointer
        newNode->setNext(insertionNode->getNext());

        //set insertion node's next pointer to new node
        insertionNode->setNext(newNode);

        //return status code
        return ELEMENT_ADDED;
    }
}

template<class dataType, typename searchType>
inline int SortedList<dataType, searchType>::remove(dataType& value) {
    Node<dataType>* currNode = head;
    Node<dataType>* prevNode = nullptr;

    //check if list is empty
    if (currNode == nullptr) {
        return ELEMENT_NOT_FOUND;
    }

    //loop through list until end or element is found
    while (currNode != nullptr) {
        //check if current node is the node to be removed
        if (&value == currNode->getPointer()) {
            //check if current node is head
            if (currNode == head) {
                //update head pointer to deletion node's next pointer
                head = currNode->getNext();
            }
            else {
                //update previous node's next pointer to deletion node's next pointer
                prevNode->setNext(currNode->getNext());
            }

            //delete found node
            delete currNode;

            //return status code
            return ELEMENT_DELETED;
        }

        //update search nodes
        prevNode = currNode;
        currNode = currNode->getNext();
    }

    //return status code
    return ELEMENT_NOT_FOUND;
}

template<class dataType, typename searchType>
dataType* SortedList<dataType, searchType>::get(int i) {
    //init current node
    Node<dataType>* currNode = head;

    //iterate through list until end
    for (int j = 0; j < i; j++) {
        //check if current node is the node to be removed
        if (currNode == nullptr) {
            //return null pointer as index not found
            return nullptr;
        }

        //update current node
        currNode = currNode->getNext();
    }

    //check that node is not null before accessing
    if (currNode != nullptr) {
        //return node data pointer
        return currNode->getPointer();
    }
    else {
        //return null pointer
        return nullptr;
    }
}

template<class dataType, typename searchType>
int SortedList<dataType, searchType>::size() {
    //init counter
    int size = 0;
    //init current node
    Node<dataType>* currNode = head;

    //iterate through list until end
    while (currNode != nullptr) {
        //increment counter
        size++;

        //update current node
        currNode = currNode->getNext();
    }

    //return size
    return size;
};

template<class dataType, typename searchType>
inline dataType* SortedList<dataType, searchType>::find(const searchType& searchTerm) {
    //init min, max & mid
	int min = 0;
	int max = (this->size() - 1);
	int mid;

	//loop until list is empty
	while (min <= max) {
		//get mid value
		mid = min + ((max - min)/2);

		//trim left
		if (*this->get(mid) < searchTerm) {
			min = mid + 1;
		}
		//trim right
		else if (*this->get(mid) > searchTerm) {
			max = mid - 1;
		}
		//if match found
		else {
			//match found
			return this->get(mid);
		}
	}

	//return null pointer as term not found
	return nullptr;
}

template<class dataType, typename searchType>
inline dataType* SortedList<dataType, searchType>::findNearest(const searchType& searchTerm) {
    //init min, max & mid
	int min = 0;
	int max = (this->size() - 1);
	int mid;

	//loop until list is empty
	while (min <= max) {
		//get mid value
		mid = min + ((max - min)/2);

		dataType* m = this->get(mid);

		//trim left
		if (*m < searchTerm) {
			min = mid + 1;
		}
		//trim right
		else if (*m > searchTerm) {
			max = mid - 1;
		}
		//if match found
		else {
			//match found
			return m;
		}
	}

	//return closest found value if direct match is not found
	return this->get(mid);
}

template<class dataType, typename searchType>
inline std::string SortedList<dataType, searchType>::toString() {
    //init string stream
    std::ostringstream* ss = new std::ostringstream();

    //init current node
    Node<dataType>* currNode = head;

    *ss << "head";

    //itterate through list until end
    while (currNode != nullptr) {
        //write current node data to string stream
        *ss << " -> ";
        *ss << currNode->getData();

        //update current node
        currNode = currNode->getNext();
    }

    //return string stream as string
    return ss->str();
}

template<class dataType, typename searchType>
inline int SortedList<dataType, searchType>::save(const std::string& filename) {
    //open file output stream
    std::ofstream file(filename);

    //check if file is open
    if (!file.is_open()) {
        return FILE_ERROR;
    }

    //init current node
    Node<dataType>* currNode = head;

    //itterate through list until end
    while (currNode != nullptr) {
        //write current node data to file
        file << currNode->getData() << std::endl;

        //update current node
        currNode = currNode->getNext();
    }

    //close file
    file.close();

    //return success code
    return FILE_WRITTEN;
}

template<class dataType, typename searchType>
inline int SortedList<dataType, searchType>::load(const std::string& filename) {
    //do things to load data from file
    //open file input stream
    std::ifstream file(filename);

    //check if file is open
    if (!file.is_open()) {
        return FILE_NOT_FOUND;
    }

    while (file.peek() != EOF) {
        //init datatype
        dataType* data = new dataType();

        //read file into data
        file >> *data;

        //check if data read is valid
        if (file.bad() && !file.eof()) {
            if (file.bad()) {
                //return status code
                return FILE_ERROR;
            }
            else {
                //delete invalid data
                delete data;

                //return status code
                return FILE_PARTIALLY_READ;
            }
        }
        else {
            //insert data into list
            this->insert(*data);
        }

        //move stream to next line or end of file
        while (file.peek() == '\n') {
            file.ignore();
        }
    }

    //close file
    file.close();

    //return success code
    return FILE_READ;
}

template<class dataType, typename searchType>
SortedList<dataType, searchType>* SortedList<dataType, searchType>::operator+=(SortedList<dataType, searchType>* l) {
    //loop for all nodes in new list
    for (int i = 0; i < l->size(); i++) {
        //insert data into this list
        this->insert(*l->get(i));
    }

    //return current object
    return this;
}

template<class dataType, typename searchType>
std::ostream& operator<<(std::ostream& os, SortedList<dataType, searchType>* list) {
    //Add toString to output stream
    os << list->toString();

    //return output stream
    return os;
}

#endif
