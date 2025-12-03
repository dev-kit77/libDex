#include "interface.h"
#include <cfloat>
#include <climits>
#include <iostream>
#include <string>

int main() {
    //test txt print
    interface::printTXT("./res/libdex.txt");

    //test separator
    interface::separator();

    //test message print
    interface::printMessage("Welcome to the Interface Test!");

    //test newLine
    interface::newLine();

    //test int reading with no given bounds
    int returnInt = interface::getInt("Please enter an integer");

    //print return value
    cout << "Return Value: " << returnInt << endl;

    //test int reading with lower bound
    returnInt = interface::getInt("Please enter an integer > 0", 0);

    //print return value
    cout << "Return Value: " << returnInt << endl;

    //test int reading with upper bound
    returnInt = interface::getInt("Please enter an integer < 0", INT_MIN, 0);

    //print return value
    cout << "Return Value: " << returnInt << endl;

    //test double reading with no given bounds
    double returnDbl = interface::getDouble("Please enter a double");

    //print return value
    cout << "Return Value: " << returnDbl << endl;

    //test double reading with lower bound
    returnDbl = interface::getDouble("Please enter a double > 0", 0.0);

    //print return value
    cout << "Return Value: " << returnDbl << endl;

    //test double reading with upper bound
    returnDbl = interface::getDouble("Please enter a double < 0", -DBL_MAX, 0.0);

    //print return value
    cout << "Return Value: " << returnDbl << endl;

    //test string reading with no given bounds
    string stringRet = interface::getString("Please enter a String");

    //print result
    cout << "Return Value: " <<stringRet << endl;

    //test string reading with set length
    stringRet = interface::getString("Please enter a String < 10 Characters", 10);

    //print result
    cout << "Return Value: " << stringRet << endl;

    //test menu
    int returnVal = interface::menu({"this", "that", "the other"});

    //print return value
    cout << "Return Value: " << returnVal << endl;

    //exit program
    return 0;
}
