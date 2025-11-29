#include "interface.h"
#include <cfloat>
#include <climits>
#include <iostream>
#include <string>

using namespace interface;

int main() {
    //test txt print
    printTXT("libdex.txt");

    //test separator
    separator();

    //test message print
    printMessage("Welcome to the Interface Test!");

    //test newLine
    newLine();

    //test int reading with no given bounds
    int returnInt = getInt("Please enter an integer");

    //print return value
    cout << "Return Value: " << returnInt << endl;

    //test int reading with lower bound
    returnInt = getInt("Please enter an integer > 0", 0);

    //print return value
    cout << "Return Value: " << returnInt << endl;

    //test int reading with upper bound
    returnInt = getInt("Please enter an integer < 0", INT_MIN, 0);

    //print return value
    cout << "Return Value: " << returnInt << endl;

    //test double reading with no given bounds
    double returnDbl = getDouble("Please enter a double");

    //print return value
    cout << "Return Value: " << returnDbl << endl;

    //test double reading with lower bound
    returnDbl = getDouble("Please enter a double > 0", 0.0);

    //print return value
    cout << "Return Value: " << returnDbl << endl;

    //test double reading with upper bound
    returnDbl = getDouble("Please enter a double < 0", -DBL_MAX, 0.0);

    //print return value
    cout << "Return Value: " << returnDbl << endl;

    //test string reading with no given bounds
    string stringRet = getString("Please enter a String");

    //print result
    cout << "Return Value: " <<stringRet << endl;

    //test string reading with set length
    stringRet = getString("Please enter a String < 10 Characters", 10);

    //print result
    cout << "Return Value: " << stringRet << endl;

    //test menu
    int returnVal = menu({"this", "that", "the other"});

    //print return value
    cout << "Return Value: " << returnVal << endl;

    //exit program
    return 0;
}
