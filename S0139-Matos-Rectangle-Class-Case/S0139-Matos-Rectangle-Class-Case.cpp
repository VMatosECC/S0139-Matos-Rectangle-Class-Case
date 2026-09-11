

#include <iostream>
#include "Rectangle.h"
using namespace std;

void showBox(Rectangle& r) {
    cout << "FRIEND Lenth: " << r.length << endl;
    cout << "FRIEND Width: " << r.width << endl;
}
// Caution. This should give errors (showBox2 is NOT a Rectangle's friend)
//void showBox2(Rectangle& r) {
//    cout << "NOT A FRIEND Lenth: " << r.length << endl;
//    cout << "NOT A FRIEND Width: " << r.width << endl;
//}

void experiment01()
{
    //Testing the static counter data member and static method getCount
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
}
//------------------------------------------------------------
void experiment02() {
    //Creating Rectangle objects and references to Rectangles
    Rectangle r1(11, 11);
    cout << "r1  " << r1.toString() << endl;

    Rectangle* p1 = nullptr;
    cout << "p1   " << p1 << endl;
    
    p1 = &r1;
    cout << "p1   " << p1 << endl;

    cout << "r1 length: " << r1.getLength() << endl;
    cout << "r1 length: " << p1->getLength() << endl;

    p1->setWidth(77);
    cout << "r1  " << r1.toString() << endl;
    cout << "*p1 " << p1->toString() << endl;

    r1.setWidth(88);
    cout << "r1  " << r1.toString() << endl;

    p1->setWidth(99);
    cout << "r1  " << r1.toString() << endl;

    p1 = new Rectangle(55, 66);

    Rectangle* p1Back = p1;

    cout << "r1  " << r1.toString() << endl;

    cout << "*p1  " << p1->toString() << endl;

    delete p1;
}
//--------------------------------------------------------
void experiment03()
{
    // Cloning Rectangles using a DEEP COPY approach
    // Implementing the Rule of three (copy constructor + 
    // copy assignment + destuctor)
    
    Rectangle r1(11, 11, "Pink");
    cout << "r1 " << r1.toString() << endl;

    Rectangle r2(r1);
    cout << "r2 " << r2.toString() << endl;

    Rectangle r3 = r1;
    cout << "r3 " << r3.toString() << endl;

    Rectangle r4(2, 4, "Navy Blue");
    cout << "r4 " << r4.toString() << endl;

    r4 = r1;
    cout << endl;
    cout << "r1 " << r1.toString() << endl;
    cout << "r4 " << r4.toString() << endl;
    cout << "r4 " << r4 << endl;
}

int main()
{
    //experiment01();
    //experiment02();
    experiment03();  
    cout << "All done!\n";
}

