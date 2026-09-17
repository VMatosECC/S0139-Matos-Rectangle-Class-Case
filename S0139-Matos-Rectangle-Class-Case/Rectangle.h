#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Shape.h"
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
class Rectangle : public Shape
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
		this->length = abs(lengthValue);
	}

	void setWidth(double widthValue) {
		this->width = abs(widthValue);
	}

	void setColor(string colorValue) {
		*this->pcolor = colorValue;
	}
	//Accessors
	double getLength() const { return length; }
	double getWidth() const { return width; }
	string getColor() const { return *pcolor; }
	
	//Constructor (condensed)
	Rectangle(double lengthValue = 0, double widthValue = 0, string colorValue = "White") 
		: Shape()
	{
		setLength(lengthValue);
		setWidth(widthValue);
		pcolor = new string(colorValue);
		counter++;
	}

	//Copy-Constructor (Deep copy)
	Rectangle(const Rectangle& other) 
		: Shape()
	{
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

	//User-defined Methods --------------------------------------------------
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

	double getArea() const {
		return width * length;
	}

	double getPerimeter() const {
		return 2 * (width + length);
	}

	//CAUTION - showBox should declare its parameter as a const
	friend void showBox(Rectangle& r);

	friend ostream& operator<< (ostream& sout, const Rectangle& r);

	////Version1 - operator+ as a function member
	//Rectangle operator+ (const Rectangle& other) {
	//	Rectangle rtemp;
	//	rtemp.setLength(this->length + other.length);
	//	rtemp.setWidth(this->width + other.width);
	//	rtemp.pcolor = new string();
	//	*rtemp.pcolor = *(this->pcolor)  + " + " +  *(other.pcolor);
	//	return rtemp;
	//}

	////Version2 - operator+ as a friend fuction
	friend Rectangle operator+ (const Rectangle& left, const Rectangle& rhs)
	{
		Rectangle temp;
		temp.setLength(left.length + rhs.length);
		temp.setWidth(left.length + rhs.width);
		temp.pcolor = new string();
		temp.setColor(left.getColor() +  + "+"  + rhs.getColor());
		return temp;
	}
	
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

