// barchartanimate.h
// barchartanimate takes in .txt file data and constructs a barframe
// the frames are then displayed in rapid succession to make an animation

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used in autograder, do not remove
#include "barchart.h"

using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string pTitle;
    string pXlabel;
    string pSource;
    int currentColor = 0;
    
    // private helper function to set the color from the COLORS vector to the
    // proper category when adding frames. 
    void setColor(string category) {
        if(colorMap.find(category) == colorMap.end()) {
            int variable = COLORS.size();
            if(currentColor == variable) {
                currentColor = 0;
            }
            colorMap[category] =  COLORS[currentColor];
            currentColor++;
        }
    }
    // private helper function help parse the lines in the .txt files to get
    // the proper variables needed to add bars to the frame
    void parseLine(string line, BarChart& b) {
        stringstream word(line);
        string frame, name, throwaway, svalue, category;
        getline(word, frame, ',');
        getline(word, name, ','); //name
        getline(word, throwaway, ','); //not needed
        getline(word, svalue, ','); //value
        int value = stoi(svalue);
        getline(word, category, '\n'); // category
        b.setFrame(frame);
        b.addBar(name, value, category);
        setColor(category);
    }

 public:

    // a parameterized constructor:
    // This function will set the default values for the private member
    // variables and create and array barcharts with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        pSource = source;
        pXlabel = xlabel;
        pTitle = title;

        capacity = 4;
        size = 0;
        barcharts = new BarChart[4];
    }

    //
    // destructor:
    // this is automatically called by c++ clear allocated memory
    virtual ~BarChartAnimate() {

        if(barcharts != nullptr) {
            delete[] barcharts;
        }
    }

    // addFrame:
    // adds a new frame to the barcharts array from the file. makes use of the
    // two private helper functions fill in the array with the correct values
    // makes sure that if size reaches overall capacity of the array then that
    // capacity is doubled
    void addFrame(ifstream &file) {
        string throwaway, line;
        getline(file, throwaway);
        if (!file.fail()) {
            string sizeTemp;
            getline(file, sizeTemp);
            int size = stoi(sizeTemp);
            BarChart b(size);
            if (this->size == capacity)
            {
                int newCapacity = capacity * 2;
                BarChart* temp = new BarChart[newCapacity];
                for (int i = 0; i < this->size; ++i)
                {
                    temp[i] = barcharts[i];
                }
                delete[] barcharts;
                barcharts = temp;
                capacity = newCapacity;
            }
            for(int i = 0; i < size; i++) {
                getline(file, line);
                parseLine(line, b);
            }
            this->barcharts[this->size] = b;
            this->size++;
        }
    }

    // animate:
    // this function will animate each frame by playing them in rapid succession
    // this means that a still image of the barframe is displayed and then the
    // the console is cleared and replaced with the next frame appear like an
    // animation
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
		int numLoops = endIter;
		if(endIter == -1) {
		    numLoops = size;
		}
		const string BLACK("\033[1;37m");
		for(int i = 0; i < numLoops; i++) {
		    usleep(3 * microsecond);
		    output << CLEARCONSOLE;
		    output << BLACK << pTitle << endl;
		    output << BLACK << pSource << endl;
		    barcharts[i].graph(output, colorMap, top);
		    output << BLACK << pXlabel << endl;
		    output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
		}
	}

    //
    // Public member function.
    // This function will return the size of the barcharts array
    int getSize(){
        return size;
    }

    //
    // Public member function.
    // allows for public access to the barcharts array
    // if the index is out of bounds then an error is thrown
    BarChart& operator[](int i){
        if (i < 0 || i >= size)
        {
         throw out_of_range("barchartanimate: i out of bounds");
        }
        return barcharts[i];
    }
};
