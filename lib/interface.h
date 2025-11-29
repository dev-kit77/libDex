/**
 * Basic C++ Console Interface Library for user interaction.
 * Version 1.00
 * Kit Cochrane
 * Header File
 */

//header guard
#ifndef INTERFACE_H
#define INTERFACE_H

//include necessary libraries
#include <cfloat>
#include <locale>
#include <string>
#include <vector>

//add std namespace
using namespace std;

namespace interface {
    //general functions
    /**
    * Prints a message to the console.
    *
    * @param message: The message to be printed.
    */
    void printMessage(const string& message = "This is a Message");

    /**
    * Prints a TXT file to the console.
    *
    * @param filename: The filename of the logo to be printed.
    */
    void printTXT(const string& filename);


    /**
    * Prints a new line to the console.
    */
    void newLine();

    /**
    * Prints a separator line to the console of specified length.
    */
    void separator(int length = 80, char symbol = '-');

    //menu functions
    /**
    * Displays a menu with the given choices and returns the user's selection.
    *
    * @param choices: The menu choices.
    *
    * @return The user's selection as int.
    */
    int menu(const vector<string>& choices);

    //input retrival functions
    /**
    * Prints a prompt to the console and retrieves an integer input from the user.
    *
    * @param prompt: The prompt to be printed.
    *
    * @return The user's input as int.
    */
    int getInt(const string& prompt = "Please enter an integer", int min = INT_MIN, int max = INT_MAX);

    /**
    * Prints a prompt to the console and retrieves a double input from the user.
    *
    * @param prompt: The prompt to be printed.
    *
    * @return The user's input as double.
    */
    double getDouble(const string& prompt = "Please enter a double", double min = -DBL_MAX, double max = DBL_MAX);

    /**
    * Prints a prompt to the console and retrieves a string input from the user.
    *
    * @param prompt: The prompt to be printed.
    *
    * @return The user's input as string.
    */
    string getString(const string& prompt = "Please enter a string", int length = 20);
}

//close header guard
#endif
