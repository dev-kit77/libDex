//header includes
#include "codes.h"
#include "interface.h"
#include "sortedList.hpp"
#include "member.h"

//standard library includes
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

int main() {
    //test txt print
    interface::printTXT("./res/libdex.txt");

    //test separator
    interface::separator();

    //test message print
    interface::printMessage("Welcome to the Data Structure Test!");

    //test newLine
    interface::newLine();

    /**
     * The following code tests the functionality of the SortedList template class with basic data types.
     */

    //init sorted list of ints
    SortedList<int, int>* sortedList = new SortedList<int, int>();

    //init random number generator
    srand((unsigned) time(NULL));

    //init array of ints to point to
    int values[20];

    //print init message
    interface::printMessage("Initializing int array with random values: ");

    //fill array with random values
    for (int i = 0; i < 20; i++) {
        //get random value
        values[i] = rand() % 100;

        //print current value
        if (i == 0) {
            cout << i << ": " << values[i];
        } else {
            cout << ", " << i << ": " << values[i];
        }
    }

    //print newline
    interface::newLine();

    //init return value to store the result of function calls
    int returnValue;

    //print divider
    interface::separator();
    interface::printMessage("Testing insertions");
    interface::separator();

    //test insertions
    interface::printMessage("Inserting values into the sorted list:");
    interface::separator();

    //print value
    interface::printMessage("Inserting value: " + std::to_string(values[0]));

    //insert value
    returnValue = sortedList->insert(values[0]);

    //check if value was inserted successfully
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Value inserted successfully.");
    } else {
        interface::printMessage("Fail: Failed to insert value.");
    }

    //print list
    interface::printMessage("Printing list for order verification:");
    std::cout << sortedList << std::endl;

    //print newline
    interface::newLine();

    //print value
    interface::printMessage("Inserting value: " + std::to_string(values[1]));

    //insert value
    returnValue = sortedList->insert(values[1]);

    //check if value was inserted successfully
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Value inserted successfully.");
    } else {
        interface::printMessage("Fail: Failed to insert value.");
    }

    //print list
    interface::printMessage("Printing list for order verification:");
    std::cout << sortedList << std::endl;

    //print newline
    interface::newLine();

    //print value
    interface::printMessage("Inserting value: " + std::to_string(values[2]));

    //insert value
    returnValue = sortedList->insert(values[2]);

    //check if value was inserted successfully
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Value inserted successfully.");
    } else {
        interface::printMessage("Fail: Failed to insert value.");
    }

    //print list
    interface::printMessage("Printing list for order verification:");
    std::cout << sortedList << std::endl;

    //print newline
    interface::newLine();

    //print value
    interface::printMessage("Inserting value: " + std::to_string(values[3]));

    //insert value
    returnValue = sortedList->insert(values[3]);

    //check if value was inserted successfully
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Value inserted successfully.");
    } else {
        interface::printMessage("Fail: Failed to insert value.");
    }

    //print list
    interface::printMessage("Printing list for order verification:");
    std::cout << sortedList << std::endl;

    //print newline
    interface::newLine();

    //print value
    interface::printMessage("Inserting value: " + std::to_string(values[4]));

    //insert value
    returnValue = sortedList->insert(values[4]);

    //check if value was inserted successfully
    if (returnValue == ELEMENT_ADDED) {
        interface::printMessage("Pass: Value inserted successfully.");
    } else {
        interface::printMessage("Fail: Failed to insert value.");
    }

    //print list
    interface::printMessage("Printing list for order verification:");
    std::cout << sortedList << std::endl;

    //print newline
    interface::newLine();

    //test adding a value already in list
    interface::printMessage("Inserting duplicate value: " + std::to_string(values[0]));

    //insert value
    returnValue = sortedList->insert(values[0]);

    //check if value was inserted successfully
    if (returnValue == ELEMENT_ALREADY_EXISTS) {
        interface::printMessage("Pass: Duplicate value detected.");
    }
    else {
        interface::printMessage("Fail: Duplicate value not detected.");
    }

    //print list
    interface::printMessage("Printing list for order verification:");
    std::cout << sortedList << std::endl;

    //print divider
    interface::separator();
    interface::printMessage("Testing Get Method");
    interface::separator();

    //test get
    interface::printMessage("Getting value: " + std::to_string(1));
    int* value = sortedList->get(1);
    interface::printMessage("Value retrieved: " + std::to_string(*value));
    //print list
    interface::printMessage("Printing list for order verification:");
    std::cout << sortedList << std::endl;

    //print divider
    interface::separator();
    interface::printMessage("Testing Remove Method");
    interface::separator();

    //test removing a value from list
    interface::printMessage("Removing value: " + std::to_string(values[0]));
    sortedList->remove(values[0]);

    //print list
    interface::printMessage("Printing list for order verification:");
    std::cout << sortedList << std::endl;

    //print new line
    interface::newLine();

    //test removing head from list
    interface::printMessage("Removing head: " + std::to_string(values[4]));
    sortedList->remove(values[4]);

    //print list
    interface::printMessage("Printing list for order verification:");
    std::cout << sortedList << std::endl;

    //print divider
    interface::separator();
    interface::printMessage("Testing Find Method");
    interface::separator();

    //print message
    interface::printMessage("Inserting remaining values:");

    //insert rest of values into list
    for (int i = 5; i < 20; i++) {
        sortedList->insert(values[i]);
    }

    //print list
    interface::printMessage("Printing list for order verification:");
    std::cout << sortedList << std::endl;

    //print new line
    interface::newLine();

    //test find in list
    interface::printMessage("Finding value: " + std::to_string(values[10]));

    //search list
    int* searchResult = sortedList->find(values[10]);

    //check result
    if (searchResult != nullptr) {
        interface::printMessage("Pass: Value found.");
        cout << "Value found at index: " << *searchResult << std::endl;
    }
    else {
        interface::printMessage("Fail: Value not found.");
    }

    //print newline
    interface::newLine();

    //test find on value not in list
    interface::printMessage("Finding value not in list: " + std::to_string(values[4]));

    //search list
    searchResult = sortedList->find(values[4]);

    //check result
    if (searchResult == nullptr) {
        interface::printMessage("Pass: Value not found.");
    }
    else {
        interface::printMessage("Fail: Value found.");
    }

    //print divider
    interface::separator();
    interface::printMessage("Saving Test");
    interface::separator();

    //test saving list to file
    interface::printMessage("Saving list to file: testList.txt");

    //save file
    returnValue = sortedList->save("testList.txt");

    //check result
    if (returnValue == FILE_WRITTEN) {
        interface::printMessage("Pass: File has been written.");
    }
    else {
        interface::printMessage("Fail: File not written.");
    }

    //print newline
    interface::newLine();

    //print file for validation
    interface::printMessage("Printing file for validation:");
    interface::printTXT("testList.txt");

    //print newline
    interface::newLine();

    //print divider
    interface::separator();
    interface::printMessage("Loading Test");
    interface::separator();

    //init new list to load file back into
    SortedList<int, int>* newList = new SortedList<int, int>();

    //test loading list from file
    interface::printMessage("Loading list from file: testList.txt");

    //load file
    returnValue = newList->load("testList.txt");

    //check result
    if (returnValue == FILE_READ) {
        interface::printMessage("Pass: File has been read.");
    }
    else {
        interface::printMessage("Fail: File not read.");
    }

    //print list
    interface::printMessage("Printing list for order verification:");
    std::cout << sortedList << std::endl;

    //print newline
    interface::newLine();

    //print new list for validation
    interface::printMessage("Printing new list for validation:");
    std::cout << newList << std::endl;

    //print newline
    interface::newLine();

    //print new list for validation
    interface::printMessage("Testing += overload:");

    //execute
    *sortedList += newList;

    //print newline
    interface::newLine();

    //print new list for validation
    interface::printMessage("Printing list for validation:");
    std::cout << sortedList << std::endl;

    //print divider
    interface::separator();
    interface::printMessage("Complex Type Tests");
    interface::separator();

    //test loading list from file
    interface::printMessage("Loading list from file: members.txt");

    //init new list member list
    SortedList<Member, std::string>* memberList = new SortedList<Member, std::string>();

    //load file
    returnValue = memberList->load("libdex/members.txt");

    //check result
    if (returnValue == FILE_READ) {
        interface::printMessage("Pass: File has been read.");
    }
    else {
        interface::printMessage("Fail: File not read.");
    }

    //print member list
    interface::printMessage("Printing member list for verification:");
    std::cout << memberList << std::endl;

    //print newline
    interface::newLine();

    //exit program
    return 0;
}
