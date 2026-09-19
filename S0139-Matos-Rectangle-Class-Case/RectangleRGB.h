#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Shape.h"
#include "RGBColor.h"
using namespace std;

//=====================================================================
// RectangleRGB.h
// CS2 Lab — RectangleRGB class

//This class models a geometric RectangleRGB that stores length, width,
//an embedded RGBcolor object, and a static object counter,
//It provides accessors, mutators, area/perimeter calculations,
//a friend `operator<<` for human-readable output, and a friend showBox()
//function to demonstrate security risks when privacy is bypassed.
// 
// Composition: RectangleRGB OWNS an RGBColor (embedded value).
// No Rule of Three needed — compiler-generated special members
// handle copy and destruction correctly.
//
// Author : V. Matos  —  El Camino College
//=====================================================================
 
class RectangleRGB : public Shape {
private:
    double   length;
    double   width;
    RGBColor color;      // COMPOSITION — embedded value, not a pointer
    static int counter;

public:
    //--------------------------------------------------------
    // Mutators
    //--------------------------------------------------------
    void setLength(double lValue)    { length = abs(lValue); }
    void setWidth(double wValue)     { width = abs(wValue); }
    void setColor(RGBColor cValue)   { color = cValue; }

    //--------------------------------------------------------
    // Accessors
    //--------------------------------------------------------
    double   getLength() const { return length; }
    double   getWidth()  const { return width; }
    RGBColor getColor()  const { return color; }

    //--------------------------------------------------------
    // Constructor
    // No Rule of Three needed — RGBColor is a value type.
    // The compiler-generated copy constructor, operator=,
    // and destructor all work correctly automatically.
    //--------------------------------------------------------
    RectangleRGB(double lValue = 0,
        double wValue = 0,
        RGBColor cValue = RGBColor::White())
        : Shape()
    {
        setLength(lValue);
        setWidth(wValue);
        setColor(cValue);
        counter++;
    }

    //--------------------------------------------------------
    // Destructor — no heap to free; just decrement counter
    //--------------------------------------------------------
    ~RectangleRGB() {
        cout << "+ RectangleRGB destroyed " << this << endl;
        counter--;
    }

    //--------------------------------------------------------
    // Utility methods
    //--------------------------------------------------------
    double getArea()      const { return length * width; }
    double getPerimeter() const { return 2.0 * (length + width); }
    static int getCount() { return counter; }

    string toString() const {
        ostringstream sout;
        sout << this
            << " RectangleRGB [Length: " << length
            << ", Width: " << width
            << ", Color: " << color
            << "]";
        return sout.str();
    }

    //--------------------------------------------------------
    // Friend functions
    //--------------------------------------------------------
    friend ostream& operator<<(ostream& os, const RectangleRGB& r) {
        os << r.toString();
        return os;
    }

    friend void showBox(const RectangleRGB& r) {
        cout << "Box [length: " << r.length
            << ", width: " << r.width
            << ", color: " << r.color
            << "]\n";
    }

	//----------------------------------------------------------
    // operator+ — adds dimensions, blends colors
    // NOTE: RGBColor::operator+ already calls mix() and returns
    // a new blended RGBColor — we simply use it here.
    //----------------------------------------------------------
	friend RectangleRGB operator+(const RectangleRGB& lhs,
		const RectangleRGB& rhs) {
		return RectangleRGB(
			lhs.length + rhs.length,
			lhs.width + rhs.width,
			lhs.color + rhs.color
		);
	}
};

// Static member initialization
int RectangleRGB::counter = 0;