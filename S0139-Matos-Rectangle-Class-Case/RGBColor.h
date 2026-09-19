//============================================================
// RGBColor.h
// CS2 Lab - RGBColor Class Definition and Implementation
//
// Author : V. Matos  -  El Camino College
//============================================================
#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class RGBColor {
private:
    int red;
    int green;
    int blue;

    // Keep channel in the range [0, 255]
    static int clamp255(int value) {
        if (value < 0) return 0;
        if (value > 255) return 255;
        return value;
    }

public:
    //--------------------------------------------------------
    // Constructors
    //--------------------------------------------------------
    RGBColor() : red(0), green(0), blue(0) {}

    RGBColor(int r, int g, int b) {
        red = clamp255(r);
        green = clamp255(g);
        blue = clamp255(b);
    }

    // Construct from packed 0xRRGGBB value
    RGBColor(unsigned int hexColor) {
        red = (hexColor >> 16) & 0xFF;
        green = (hexColor >> 8) & 0xFF;
        blue = hexColor & 0xFF;
    }

    //--------------------------------------------------------
    // Getters
    //--------------------------------------------------------
    int getRed()   const { return red; }
    int getGreen() const { return green; }
    int getBlue()  const { return blue; }

    //--------------------------------------------------------
    // Setters
    //--------------------------------------------------------
    void setRed(int r) { red = clamp255(r); }
    void setGreen(int g) { green = clamp255(g); }
    void setBlue(int b) { blue = clamp255(b); }

    //--------------------------------------------------------
    // complement() — subtract each channel from 255
    //--------------------------------------------------------
    RGBColor complement() const {
        return RGBColor(255 - red, 255 - green, 255 - blue);
    }

    //--------------------------------------------------------
    // mix() — simple linear average of each channel
    //--------------------------------------------------------
    RGBColor mix(const RGBColor& other) const {
        return RGBColor(
            (red + other.red) / 2,
            (green + other.green) / 2,
            (blue + other.blue) / 2
        );
    }

    //--------------------------------------------------------
    // mixWeighted() — lerp: t=1.0->this, t=0.0->other
    //--------------------------------------------------------
    RGBColor mixWeighted(const RGBColor& other, double t) const {
        return RGBColor(
            clamp255((int)(red * t + other.red * (1.0 - t))),
            clamp255((int)(green * t + other.green * (1.0 - t))),
            clamp255((int)(blue * t + other.blue * (1.0 - t)))
        );
    }

    //--------------------------------------------------------
    // toGrayscale() — ITU-R BT.601 luminance formula
    // Y = 0.299R + 0.587G + 0.114B
    //--------------------------------------------------------
    RGBColor toGrayscale() const {
        int gray = (int)(0.299 * red + 0.587 * green + 0.114 * blue);
        return RGBColor(gray, gray, gray);
    }

    //--------------------------------------------------------
    // toHex() — pack channels into 0xRRGGBB
    //--------------------------------------------------------
    unsigned int toHex() const {
        return (red << 16) | (green << 8) | blue;
    }

    //--------------------------------------------------------
    // toHexString() — "#RRGGBB" using sstream and iomanip
    // Note: setfill() is sticky; setw() resets after each use
    //--------------------------------------------------------
    string toHexString() const {
        ostringstream oss;
        oss << "#"
            << uppercase
            << setfill('0')
            << hex
            << setw(2) << red
            << setw(2) << green
            << setw(2) << blue;
        return oss.str();
    }

    //--------------------------------------------------------
    // toString() — shows rgb() and hex notations
    //--------------------------------------------------------
    string toString() const {
        ostringstream oss;
        oss << "rgb("
            << setw(3) << red << ", "
            << setw(3) << green << ", "
            << setw(3) << blue << ")  "
            << toHexString();
        return oss.str();
    }

    //--------------------------------------------------------
    // Static factory methods
    //--------------------------------------------------------
    static RGBColor Black() { return RGBColor(0, 0, 0); }
    static RGBColor White() { return RGBColor(255, 255, 255); }
    static RGBColor Red() { return RGBColor(255, 0, 0); }
    static RGBColor Green() { return RGBColor(0, 255, 0); }
    static RGBColor Blue() { return RGBColor(0, 0, 255); }
    static RGBColor Yellow() { return RGBColor(255, 255, 0); }
    static RGBColor Cyan() { return RGBColor(0, 255, 255); }
    static RGBColor Magenta() { return RGBColor(255, 0, 255); }
    static RGBColor Orange() { return RGBColor(255, 128, 0); }

    //--------------------------------------------------------
    // Operator overloads
    //--------------------------------------------------------
    RGBColor operator+(const RGBColor& other) const {
        return mix(other);
    }

    bool operator==(const RGBColor& other) const {
        return red == other.red &&
            green == other.green &&
            blue == other.blue;
    }

    bool operator!=(const RGBColor& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const RGBColor& c) {
        os << c.toString();
        return os;
    }
};
