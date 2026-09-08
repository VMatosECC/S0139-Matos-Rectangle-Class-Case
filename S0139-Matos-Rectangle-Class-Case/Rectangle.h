#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Rectangle
{
private:
	//Data members
	double length;
	double width;
	static int counter;

public:
	//Mutators
	void setLength(double lengthValue) {
		length = abs(lengthValue);
	}

	void setWidth(double widthValue) {
		width = abs(widthValue);
	}
	//Accessors
	double getLength() { return length; }
	double getWidth() { return width; }
	
	//Constructor (condensed)
	Rectangle(double lengthValue = 0, double widthValue = 0) {
		setLength(lengthValue);
		setWidth(widthValue);
		counter++;
	}
	//Destructor
	~Rectangle() {
		cout << this << " deleted " << endl;
		counter--;
	}

	//User-defined Methods
	string toString() {
		stringstream sout;
		sout << this << " Rectangle [Length: " << getLength()
			<< ", Width: " << getWidth() << "]";
		return sout.str();
	}

	static int getCount() {
		return counter;
	}

	friend void showBox(Rectangle& r);
	friend void showBox2(Rectangle& r);
	
};

//Initialization of static data
int Rectangle::counter = 0;

