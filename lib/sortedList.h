/**
 * SortedList Library for C++
 * Version 1.00.
 * Kit Cochrane.
 * Methods are implemented in sortedList.hpp and this library should be included from sortedList.hpp.
 */
//header guard
#ifndef SORTED_LIST_H
#define SORTED_LIST_H

//header includes
#include "codes.h"

//standard library includes
#include <string>

/**
 * Node class for the sorted list. Stores a pointer to the data and a pointer to the next node.
 */
template<class T> class Node {
    public:
        /**
        * Constructor for the Node class.
        * @param data Pointer to the data to be stored in the node.
        */
        Node(T* data) : data(data), next(nullptr) {}

        /**
         * Setter for the next pointer.
         * @param next Pointer to the next node.
         */
        void setNext(Node* next) { this->next = next; }

        /**
         * Getter for the next pointer.
         * @return Pointer to the next node.
         */
        Node* getNext() { return next; }

        /**
         * Getter for the data pointer.
         * @return Pointer to the data stored in the node.
         */
        T* getPointer() { return data; }

        /**
         * Getter for the data pointer.
         * @return Pointer to the data stored in the node.
         */
        T getData() { return *data; }

    private:
        //class fields
        T* data;
        Node* next;
};

template<class dataType, typename searchType> class SortedList;
template<class dataType, typename searchType> std::ostream& operator<<(std::ostream& os, SortedList<dataType, searchType>* list);


/**
 * SortedList template class for storing and managing sorted lists by overloaded < & > comparison operators and save & load to files managed by overloaded << & >> operators.
 *
 * This class provides a sorted list implementation using a linked list data structure.
 */
template<class dataType, typename searchType>
class SortedList {
    public:
        /**
        * Constructor for SortedList.
        *
        * Initializes an empty list.
        */
        SortedList();

        /**
        * Destructor for SortedList.
        *
        * Frees the memory allocated for the list.
        */
        ~SortedList();

        /**
        * Method to insert a value into the list.
        *
        * This method inserts a value into the list while maintaining the sorted order.
        * If the value already exists in the list, it is not inserted again.
        *
        * @param value The value to be inserted.
        * @return ELEMENT_ADDED if the value was inserted successfully, ELEMENT_ALREADY_EXISTS if the value already exists, or ALLOC_ERROR if an error occurred.
        */
        int insert(dataType& value);

        /**
        * Method to remove a value from the list.
        *
        * This method removes a value from the list.
        * If the value does not exist in the list, it is not removed.
        *
        * @param value The value to be removed.
        * @return ELEMENT_DELETED if the value was removed successfully, ELEMENT_NOT_FOUND if the value was not found, or ALLOC_ERROR if an error occurred.
        */
        int remove(dataType& value);

        /**
        * Method to perform a binary search on the list.
        *
        * This method performs a binary search on the list to find a value.
        * If the value is found, its index is returned.
        * If the value is not found, NULL is returned.
        *
        * @param searchTerm The value to be searched for.
        * @return the value if found, NULL if not found.
        */
        dataType* find(const searchType& searchTerm);

        /**
        * Method to perform a binary search on the list.
        *
        * This method performs a binary search on the list to find a value.
        * If the value is found, its index is returned.
        * If the value is not found, NULL is returned.
        *
        * @param searchTerm The value to be searched for.
        * @return the value if found, nearest value otherwise.
        */
        dataType* findNearest(const searchType& searchTerm);

        /**
         * Method to get an element at a specific index.
         *
         * If the index is out of bounds, nullptr is returned.
         *
         * @param i The index of the element to retrieve.
         * @return the element at the specified index, or nullptr if the index is out of bounds.
         */
        dataType* get(int i);

        /**
         * Method to convert the list to a string representation.
         *
         * @return a string representation of the list.
         */
        std::string toString();

        /**
        * Method to get the size of the list.
        *
        * @return the size of the sorted list.
        */
        int size();

        /**
        * Method to save the list to a file using the provided filename and data type << overloading.
        *
        * If the file cannot be opened FILE_ERROR is returned.
        *
        * @param filename The name of the file to save the list to.
        * @return FILE_WRITTEN if the list was saved successfully, or an error code if an error occurred.
        */
        int save(const std::string& filename);

        /**
        * Method to load the list from a file using the provided filename and data type >> overloading.
        *
        * If the file cannot be opened FILE_NOT_FOUND is returned, if the file cannot be read FILE_ERROR is returned.
        *
        * @param filename The name of the file to load the list from.
        * @return FILE_READ if the list was loaded successfully, or an error code if an error occurred.
        */
        int load(const std::string& filename);

        /**
         * Operator overload for +=. Adds all members of the provided list to this list.
         * @param l the list to insert to the current list
         */
        SortedList<dataType, searchType>* operator+=(SortedList<dataType, searchType>* l);

        /**
         * Operator overload to print the list to an output stream.
         *
         * @param os The output stream to print the list to.
         * @param list The list to print.
         * @return The output stream.
         */
        friend std::ostream& operator<< <>(std::ostream& os, SortedList<dataType, searchType>* list);
    private:
        //class fields
        Node<dataType>* head;
};

#endif
