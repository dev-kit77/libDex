# file dictionary

# Libraries:
codes.h: Standard status and error codes
interface: Interface library to provide a standardized interface for user interaction.
sortedList: Template class data structure Library. Used for publicaton and members.
util: Utility functions

# Source:
main.cpp: stores the main method for the system and the menu namespace with all menu functions. Initalises and library loading from files.
library: Class to store and manage members and publications and related attributes. The interface for the data
member: Class to store members information, loans and reservations.
publication: Abstract Class with basic publication information, loans and reservations. Publication data types implemented as subclasses of the abstract.
reservation: Class to store cross-reference info about members and publications for their reservations.
loan: Extention of reservation to add due date and calculate penalties.

# Publication Data Types: 
Each holds data about their respective publication type and implements publication abstracts:
book
audiobook
ebook
journal
magazine
movie

# Tests:
ifTest.cpp: tester for the Interface library, Runs through input functions along with other display and menu functions.
listTest.cpp: tester for the sortedList library. Initalises a sortedList with sample data of both simple and complex data types and tests its functionality.
pubTest.cpp: tester for the Publication subclasses. Runs through subclasses testing all data types with respective sample data, along with loading and saving through the sortedList.
membtest.cpp: tester for the Member class, initalises and tests member functions with sample data, along with the connections to publications.
libtest.cpp: tester for the library class, intialises a library then tests adding & removing, searching, borrowing and reserving and saving/loading.
utiltest.cpp: tester for the Utility library, tests the levenshtien calculator and keyword extraction.
scenario.cpp: implements a preset test scenario with reading specific data.
