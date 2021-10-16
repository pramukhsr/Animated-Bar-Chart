// barchart.h
// this file contains the functions that will create each individual bar
// that will appear in the barframe.

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in autograder, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string barFrame;

 public:

    // default constructor:
    // this is the basic constructor that sets the values for the class BarChart
    BarChart() {
        capacity = 0;
        size = 0;
        bars = NULL; // change to bars = new bar[capacity];
        barFrame = "";
        
    }

    // parameterized constructor:
    // This constructor takes in size to determine the bars array capacity
    BarChart(int n) {
        capacity = n;
        bars = new Bar[capacity];
        size = 0;
        barFrame = "";
    }

    //
    // copy constructor:
    // This function creates copy variables of BarChart as this is done when
    // passing by value.
    BarChart(const BarChart& other) {
        
        this->bars = new Bar[other.capacity];
        this->size = other.size;
        this->capacity = other.capacity;
        this->barFrame = other.barFrame;
        for (int i = 0; i < other.size; ++i)
        {
            this->bars[i] = other.bars[i];
        }
    }
    //
    // copy operator=
    // The copy operator = function allows us to se values of one BarChart
    // to another.
    BarChart& operator=(const BarChart& other) {
        //BarChart bc;
        
        if (this == &other) {
            return *this;
        }
        
        delete[] bars;
        
        this->bars = new Bar[other.capacity];
        this->size = other.size;
        this->barFrame = other.barFrame;
        this->capacity = other.capacity;
        
        for (int i = 0; i < other.size; ++i)
        {
            this->bars[i] = other.bars[i];

        }
        
        return *this;
    }

    // clear
    // This function clears the bars array and reset the private members back
    // to default value.
    void clear() {
        
        if (bars != NULL) {
            delete [] bars;
        }
        
        capacity = 0;
        size = 0;
        bars = NULL;
        barFrame = "";
    }

    //
    // destructor:
    // this function is automatically called by c++ at the end of the program
    // to free all allocated memory
    virtual ~BarChart() {
        if (bars != nullptr) {
            delete [] bars;
        }
        bars = NULL;
    }

    // setFrame
    // takes in the name of the frame for the graph
    void setFrame (string frame) {
        barFrame = frame;
    }

    // getFrame()
    // returns the name of the frame for the graph
    string getFrame() {
        return barFrame;
    }

    // addBar
    // adds a bar object to to the array of bars
    // if size is equal to capacity then result in false
    // otherwise add the bar to the array bars
    bool addBar(string name, int value, string category) {
        Bar b(name, value, category);
        if(size == capacity) {
            return false;
        } else { 
            bars[size] = b;
            size++;
        }
        return true;
    }

    // getSize()
    // returns the size of the bars array
    int getSize() {
        return size;
    }

    // operator[]
    // Allows for public access of the bars array. If the index is out of bounds
    // then throw and error.
    Bar& operator[](int i) {
        if (i < 0 || i >= size)
        {
         throw out_of_range("barchart: i out of bounds");
        }
        return bars[i];
    }

    // dump
    // This function will output the contents of the bar array and will be used
    // for testing and debugging.
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
        BarChart copy(*this);
        sort(copy.bars, copy.bars + copy.size, greater<Bar>());
        output << "frame: " << this->barFrame << endl;
        for(int i = 0; i < size; i++) {
            output << copy.bars[i].getName() << " " << copy.bars[i].getValue() <<
            " " << copy.bars[i].getCategory() << endl;
        }
    }

    // graph
    // this loops through all bars and prints them out
    // the function takes the colorMap to assign a color to the bars
    // colorMap maps category -> color
    // top parameter is used to show how many bars outputted per iteration
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	sort(bars, bars + size, greater<Bar>());
    	int lenMax = 60;  // this is number of BOXs that should be printed
                          // for the top bar (max value)
        string color = "";
        int topVal = bars[0].getValue();
        for(int i = 0; i < top; i++) {
            string barstr = "";
            double currentVal = bars[i].getValue();
            for (int j = 0;
            j < static_cast<int>((currentVal / topVal) * lenMax); j++) {
                barstr += BOX;
            }
            if (colorMap.count(bars[i].getCategory()) != 0) {
                color = colorMap[bars[i].getCategory()];
            } else { // sets color to each bar
                color = BLACK;
            }
            output << color << barstr << " ";
            output << bars[i].getName() << " ";
            output << bars[i].getValue() << endl;
        }
    }
};

