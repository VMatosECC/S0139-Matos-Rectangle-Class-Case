#pragma once
#include <iostream>
using namespace std;

/**
 * @brief Abstract base class for all geometric shapes.
 */
class Shape {
public:
    virtual double getArea()        const = 0;
    virtual double getPerimeter()   const = 0;
    virtual string toString()       const = 0;
    virtual ~Shape() {}
};

