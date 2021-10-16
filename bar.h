// bar.h
// this file creates the most basic properties of the individual bars such
// as the name, value and category. It also includes the comparison
// operator definitons

#include <iostream>
#include <string>
#include "myrandom.h" // used in autograder, do not remove
using namespace std;

//
// Bar
//
class Bar {
 private:
    // Private member variables for a Bar object
    // TO DO:  Define private member variables for this class
    // NOTE: You should not be allocating memory on the heap for this class.
    int pValue;
    string pName;
    string pCategory;

 public:

    // default constructor:
    // this is the basic constructor that sets the values for the class Bar
    Bar() {
        pValue = 0;
        pName = "";
        pCategory = "";
    }

    //
    // a second constructor:
    // Parameter passed in constructor Bar object.
    // this is the constructor that takes in values for the class Bar
    Bar(string name, int value, string category) {
        pValue = value;
        pName = name;
        pCategory = category;
        
    }

    // destructor:
    // this is automatically called at the end of the program to free
    // allocated memory
    virtual ~Bar() {
        // TO DO:  Write this destructor or leave empty if not needed.
    }

    // getName:
    // returns the value stored in the name variable.
	string getName() {
        return pName;
	}

    // getValue:
    // returns value stored in the value variable.
	int getValue() {
        return pValue;    
	}

    // getCategory:
    // returns value stored in the category variable.
	string getCategory() {
        return pCategory; 
	}

	// operators
    // TO DO:  Write these operators.  This allows you to compare two Bar
    // objects.  Comparison should be based on the Bar's value.  For example:

    // less than operator comparison returns true if < is correct
	bool operator<(const Bar &other) const {
        if (pValue < other.pValue) {
            return true;
        }
        return false;
	}
    // less equal than operator comparison returns true if <= is correct
	bool operator<=(const Bar &other) const {
        if (pValue <= other.pValue) {
            return true;
        }
        return false;
	}
    // greater than operator comparison returns true if > is correct
	bool operator>(const Bar &other) const {
        if (pValue > other.pValue) {
            return true;
        }
        return false;
	}
    // greater equal than operator comparison returns true if >= is correct
	bool operator>=(const Bar &other) const {
        if (pValue >= other.pValue) {
            return true;
        }
        return false;
	}
};
