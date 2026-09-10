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
	//int* color = new int[3];
	string* pcolor = nullptr;

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

	friend void showBox(Rectangle& r);
	friend void showBox2(Rectangle& r);
	friend ostream& operator<< (ostream& sout, const Rectangle& r);
	
};

//Initialization of static data
int Rectangle::counter = 0;

ostream& operator<< (ostream& sout, const Rectangle& r)
{
	sout << r.toString();
	return sout;
}
