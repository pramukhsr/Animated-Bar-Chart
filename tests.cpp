#include <iostream>
#include <sstream>
#include <fstream>
#include "barchartanimate.h"
using namespace std;

// tests bar default constructor
// tests bar getname, getvalue, get category
bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}
// test bar parameterized constructor
// tests bar getname, getvalue, get category
bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}
bool testBarParamConstructor1() {
	Bar b("New York", 900000, "US");
    if (b.getName() != "New York") {
    	cout << "testBarParamConstructor1: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 900000) {
    	cout << "testBarParamConstructor1: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor1: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor1: all passed!" << endl;
    return true;
}
// test the greater than comarison
bool testBarComarisonGreaterThan() {
	Bar b("Chicago", 9234324, "US");
	Bar b1("New York", 9765432, "US");
    if (b>b1) {
    	cout << "testBarComarisonGreaterThan: lessthan failed" << endl;
    	return false;
    }
    
    cout << "testBarComarisonGreaterThan: all passed!" << endl;
    return true;
}
// test the greater than equal comarison
bool testBarComarisonGreaterThanEqual() {
	Bar b("Chicago", 9234324, "US");
	Bar b1("New York", 9765432, "US");
    if (b>=b1) {
    	cout << "testBarComarisonGreaterThanEqual: lessthan failed" << endl;
    	return false;
    }
    
    cout << "testBarComarisonGreaterThanEqual: all passed!" << endl;
    return true;
}
bool testBarComarisonGreaterThanEqual1() {
	Bar b("Chicago", 9234324, "US");
	Bar b1("New York", 15000000, "US");
    if (b>=b1) {
    	cout << "testBarComarisonGreaterThanEqual1: lessthan failed" << endl;
    	return false;
    }
    
    cout << "testBarComarisonGreaterThanEqual1: all passed!" << endl;
    return true;
}
// test the less than comarison
bool testBarComarisonLessThan() {
	Bar b("Chicago", 9234324, "US");
	Bar b1("New York", 9765432, "US");
    if (b1<b) {
    	cout << "testBarComarisonLessThan: lessthan failed" << endl;
    	return false;
    }
    
    cout << "testBarComarisonLessThan: all passed!" << endl;
    return true;
}
bool testBarComarisonLessThan1() {
	Bar b("Chicago", 9234324, "US");
	Bar b1("New York", 9999999, "US");
    if (b1<b) {
    	cout << "testBarComarisonLessThan1: lessthan failed" << endl;
    	return false;
    }
    
    cout << "testBarComarisonLessThan1: all passed!" << endl;
    return true;
}
// test the less than equal comarison
bool testBarComarisonLessThanEqual() {
	Bar b("Chicago", 9234324, "US");
	Bar b1("New York", 9765432, "US");
    if (b1<=b) {
    	cout << "testBarComarisonLessThanEqual: lessthan failed" << endl;
    	return false;
    }
    
    cout << "testBarComarisonLessThanEqual: all passed!" << endl;
    return true;
}
bool testBarComarisonLessThanEqual1() {
	Bar b("Chicago", 9234324, "US");
	Bar b1("New York", 9965432, "US");
    if (b1<=b) {
    	cout << "testBarComarisonLessThanEqual1: lessthan failed" << endl;
    	return false;
    }
    
    cout << "testBarComarisonLessThanEqual1: all passed!" << endl;
    return true;
}
// test Barchart default constructor
bool testBarChartDefaultConstructor(){
    BarChart b;
    if (b.getFrame() != "") {
    	cout << "testBarChartDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getSize() != 0) {
    	cout << "testBarChartDefaultConstructor: getValue failed" << endl;
    	return false;
    }
    cout << "testBarChartDefaultConstructor: all passed!" << endl;
    return true;
}
// tests the clear function
void testBarClear() {
    BarChart b(10);
    b.addBar("hello", 10, "goodbye");
    b.clear();
    if(b.getSize() == 0) {
        cout << "testBarClear: passed" << endl;
    } else {
        cout << "test failed" << endl;
    }
}
void testBarClear1() {
    BarChart b(10);
    b.addBar("hello", 10000, "goodbye");
    b.clear();
    if(b.getSize() == 0) {
        cout << "testBarClear: passed" << endl;
    } else {
        cout << "test failed" << endl;
    }
}
// tests the getSize function
void testBarChartGetSize() {
    BarChart b(10);
    
    b.addBar("", 50, "");
    b.addBar("", 50, "");
    b.addBar("", 50, "");
    b.addBar("", 50, "");
    b.addBar("", 50, "");
    b.addBar("", 50, "");
    if (b.getSize() == 6) {
        cout <<"testBarChartGetSize: passed" << endl;
    } else {
        cout << "test failed" << endl;
    }
}
void testBarChartGetSize1() {
    BarChart b(10);
    
    b.addBar("", 50, "");
    if (b.getSize() == 1) {
        cout <<"testBarChartGetSize1: passed" << endl;
    } else {
        cout << "test failed" << endl;
    }
}
// tests the dump function using cout/ also tests addbar
void testBarChartDump() {
    BarChart b(10);
    b.setFrame("100");
    b.addBar("New York", 100000, "USA");

    b.dump(cout);
}
// tests the dump function using string stream/ also tests addbar
void testBarChartDumpSS() {
    BarChart b(10);
    b.addBar("New York", 100000, "USA");
    b.addBar("LA", 600000, "USA");
    b.addBar("Miami", 900000, "USA");
    stringstream ss("");
    b.dump(ss);
    cout << ss.str() << endl;
}
// tests the graph function and the addbar
void testBarChartGraph1() {
    BarChart b(10);
    b.addBar("Chicago", 400000, "US");
    b.addBar("Paris", 500000, "France");
    string red("\033[1;36m");
    string blue("\033[1;33m");
    map<string, string> colorMap;
    colorMap["US"] = red;
    colorMap["France"] = blue;
    b.graph(cout, colorMap, 3);
}
void testBarChartGraph2() {
    BarChart b(10);
    b.addBar("Chicago", 400000, "US");
    b.addBar("Paris", 500000, "France");
    b.addBar("New York", 450000, "US");
    b.addBar("LA", 425000, "US");
    b.addBar("Miami", 350000, "US");
    b.addBar("Rome", 700000, "Italy");
    b.addBar("Florence", 200000, "Italy");
    string red("\033[1;36m");
    string blue("\033[1;33m");
    string green("\033[1;35m");
    map<string, string> colorMap;
    colorMap["US"] = red;
    colorMap["France"] = blue;
    colorMap["Italy"] = green;
    b.graph(cout, colorMap, 3);
}
// tests the animate and add frame functions for 1 iteration
void testBarChartAnimateGraph() {
    string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	bca.animate(cout, 12, 1);
}
// tests the animate and add frame functions for 10 iterations
void testBarChartAnimateGraph1() {
    string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	bca.animate(cout, 12, 10);
}


int main() {
//  testBarDefaultConstructor();
//  testBarParamConstructor();
//  testBarParamConstructor1();
// 	testBarComarisonGreaterThan();
//  testBarComarisonGreaterThanEqual1();
// 	testBarComarisonGreaterThanEqual();
// 	testBarComarisonLessThan();
//  testBarComarisonLessThan1();
// 	testBarComarisonLessThanEqual();
//  testBarComarisonLessThanEqual1();
//  testBarChartDefaultConstructor();
//  testBarClear();
//  testBarClear1()
// 	testBarChartGetSize();
//  testBarChartGetSize1();
// 	testBarChartDump();
// 	testBarChartDumpSS();
//  testBarChartGraph1();
//  testBarChartGraph2();
//  testBarChartAnimateGraph();
//  testBarChartAnimateGraph1();
	
    return 0;
}