

#include <iostream>
#include "Rectangle.h"
using namespace std;

void showBox(Rectangle& r) {
    cout << "FRIEND Lenth: " << r.length << endl;
    cout << "FRIEND Width: " << r.width << endl;
}

void showBox2(Rectangle& r) {
    cout << "FRIEND Lenth: " << r.length << endl;
    cout << "FRIEND Width: " << r.width << endl;
}

int main()
{
    cout << "Total rectangles: " << Rectangle::getCount() << endl;

    Rectangle r1(10, 10);
    cout << "Total rectangles: " << Rectangle::getCount() << endl;

    Rectangle a[3]{ r1 };
    cout << "Total rectangles: " << Rectangle::getCount() << endl;

    for (Rectangle r : a) {
        cout << r.toString() << endl;
    }

    Rectangle* p1 = new Rectangle(20, 20);
    cout << "p1   " << p1 << endl;
    cout << "*p1  " << p1->toString() << endl;

    showBox(r1);

    cout << "All done!\n";
}

