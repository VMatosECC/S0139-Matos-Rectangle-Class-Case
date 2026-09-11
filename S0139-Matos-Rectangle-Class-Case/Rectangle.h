#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

/**
 * Rectangle.h
 * Lightweight Rectangle class with instance counting and formatted output.
 *
 * This class models a geometric rectangle that stores length, width 
 * a heap-allocated color string, a static object counter, 
 * and a complete 'Rule of Three' implementation (copy constructor, 
 * copy assignment operator, and destructor) to guarantee safe deep copies. 
 * It provides accessors, mutators, area/perimeter calculations,
 * a friend `operator<<` for human-readable output, and a friend showBox()
 * function to demonstrate security risks when privacy is bypassed.
 */
class Rectangle
{
private:
	//Data members
	double length;
	double width;
	string* pcolor = nullptr;	//CAUTION!
	static int counter;

public:
	//Mutators
	void setLength(double lengthValue) {
		length = abs(lengthValue);
	}

	void setWidth(double widthValue) {
		width = abs(widthValue);
	}

	void setColor(string colorValue) {
		*pcolor = colorValue;
	}
	//Accessors
	double getLength() const { return length; }
	double getWidth() const { return width; }
	string getColor() const { return *pcolor; }
	
	//Constructor (condensed)
	Rectangle(double lengthValue = 0, double widthValue = 0, string colorValue = "White") {
		setLength(lengthValue);
		setWidth(widthValue);
		pcolor = new string(colorValue);
		counter++;
	}

	//Copy-Constructor (Deep copy)
	Rectangle(const Rectangle& other) {
		this->setLength(other.getLength());
		this->setWidth(other.width);
		this->pcolor = new string();
		//*pcolor = *(other.pcolor);
		this->setColor(*(other.pcolor));
		counter++;
	}

	//Copy-assignment operator
	Rectangle& operator= (const Rectangle& other) {
		if (this != &other) {
			this->setLength(other.length);
			this->setWidth(other.width);
			delete this->pcolor;
			pcolor = new string();
			this->setColor(*(other.pcolor));
		}
		return *this;
	}



	//Destructor
	~Rectangle() {
		cout << this << " obj deleted, heap pcolor box: " << pcolor << endl;
		delete pcolor;
		counter--;
	}

	//User-defined Methods
	string toString()  const {
		stringstream sout;
		sout << this << " Rectangle [Length: " << getLength()
			<< ", Width: " << getWidth() 
			<< ", pcolor value: " << *pcolor  
			<< ", pcolor addr: " << pcolor
			<< "]";
		return sout.str();
	}

	static int getCount() {
		return counter;
	}

	//CAUTION - showBox should declare its parameter as a const
	friend void showBox(Rectangle& r);

	friend ostream& operator<< (ostream& sout, const Rectangle& r);
	
};

// -----------------------------------------------------------------
// Initialization of static data
int Rectangle::counter = 0;

// Implementation of a friend function (operator<<)
ostream& operator<< (ostream& sout, const Rectangle& r)
{
	sout << r.toString();
	return sout;
}
