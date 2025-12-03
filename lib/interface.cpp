// include header
#include "interface.h"

// include necessary std libraries
#include <cerrno>
#include <cfloat>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// add std namespace
using namespace std;

namespace interface {
void printMessage(const string &message) { cout << message << endl; }

void printTXT(const string &filename) {
  // open input file stream
  ifstream file(filename);

  // check if file is not open
  if (!file.is_open()) {
    // print basic error
    cerr << "Interface Err: Cannot open file " << filename << "." << endl;

    // check badbit
    if (file.bad()) {
      // print badbit error
      cerr << "Fatal Err: badbit is set." << endl;
    }

    // check if fail noted by system for detailed error
    if (file.fail()) {
      // print detailed error
      cerr << "Detailed Err: " << errno << ": " << strerror(errno) << "."
           << endl;
    }
  }

  // init line string
  string line;

  // loop until no more lines
  while (getline(file, line)) {
    // print line to console
    cout << line << endl;
  }

  // close file
  file.close();
}

int getInt(const string &prompt, int min, int max) {
  // init output value
  int value;

  // clear input buffer
  cin.clear();

  // loop until valid input
  do {
    // print prompt to user
    cout << prompt << ": ";

    // get double value from user
    cin >> value;

    // print error message if previous input is invalid
    if (cin.fail()) {
      // print error message
      cerr << "Input Err: Invalid input. Please enter an integer." << endl;
    }
    // check for input bounds
    else if (value < min || value > max) {
      // print error message
      cerr << "Bounds Err: Invalid input. Please enter an integer between "
           << min << " and " << max << "." << endl;
    }
  }
  // check if input is valid
  while (cin.fail() || value < min || value > max);

  // return value
  return value;
}

double getDouble(const string &prompt, double min, double max) {
  // init output value
  double value;

  // clear input buffer
  cin.clear();

  // loop until valid input
  do {
    // print prompt to user
    cout << prompt << ": ";

    // get double value from user
    cin >> value;

    // print error message if previous input is invalid
    if (cin.fail()) {
      // print error message
      cerr << "Input Err: Invalid input. Please enter a double." << endl;
    }
    // check for input bounds
    else if (value < min || value > max) {
      // print error message
      cerr << "Bounds Err: Invalid input. Please enter a double between " << min
           << " and " << max << "." << endl;
    }
  }
  // check if input is valid
  while (cin.fail() || value < min || value > max);

  // return value
  return value;
}

string getString(const string &prompt, int length) {
  // init output value
  string input;

  // clear input buffer
  cin.clear();

  // loop until valid input
  do {
    // print prompt to user
    cout << prompt << ": ";

    // get string value from user
    cin >> input;

    // print error message if previous input is invalid
    if (cin.fail()) {
      // print error message
      cerr << "Input Err: Invalid input. Please enter a string." << endl;
    }
    // check for input bounds
    else if (input.length() > length) {
      // print error message
      cerr << "Bounds Err: Invalid input. Please enter a string shorter than "
           << length << " characters." << endl;
    }
  }
  // check if input is valid
  while (cin.fail() || input.length() > length);

  // return value
  return input;
}

void newLine() { cout << endl; }

void separator(int length, char symbol) {
  cout << string(length, symbol) << endl;
}

int menu(const vector<string> &items) {
  // init menu string
  string menu = "| Select an Option | ";

  // init index
  int index = 1;

  // loop for all menu options
  for (string option : items) {
    // add option to menu string
    menu += to_string(index) + ". " + option + " | ";

    // increment index
    index++;
  }

  // print menu to console
  separator(menu.length(), '=');
  cout << menu << endl;
  separator(menu.length(), '=');

  // print new line
  newLine();

  // get a menu selection and return output
  return getInt("Please select an option", 1, items.size());
}
} // namespace interface
