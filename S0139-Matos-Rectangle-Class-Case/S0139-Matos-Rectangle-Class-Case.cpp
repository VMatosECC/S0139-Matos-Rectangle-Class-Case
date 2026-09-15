

#include <iostream>
#include "Rectangle.h"
using namespace std;

void showBox(Rectangle& r) {
    // TEST - uncomment next statement - run experiment01. 
    // The object will be compromised. A better approach 
    // is to declare the parameter as const, that is
    // void showBox(const Rectangle& r)
    r.setColor("Ugly gray");
    cout << "FRIEND Lenth: " << r.length << endl;
    cout << "FRIEND Width: " << r.width << endl;
    cout << "FRIEND color: " << r.getColor() << endl;
}
// Caution. This should give errors (showBox2 is NOT a Rectangle's friend)
//void showBox2(Rectangle& r) {
//    cout << "NOT A FRIEND Lenth: " << r.length << endl;
//    cout << "NOT A FRIEND Width: " << r.width << endl;
//}

void experiment01()
{
    //Testing the static counter data member and static method getCount
    //Using a friend function and compromising its data
    cout << "Total rectangles: " << Rectangle::getCount() << endl;

    //create statically allocated instances of a stand-alone rectangle
    //and an array of three rectangles (partially initialized)
    Rectangle r1(10, 10);
    cout << "Total rectangles: " << Rectangle::getCount() << endl;

    Rectangle a[3]{ r1 };
    cout << "Total rectangles: " << Rectangle::getCount() << endl;

    for (Rectangle r : a) {
        cout << r.toString() << endl;
    }

    //Create a heap-allocated rectangle
    Rectangle* p1 = new Rectangle(20, 20);
    cout << "p1   " << p1 << endl;
    cout << "*p1  " << p1->toString() << endl;
    delete p1;  //remove it from the heap

    //Calling a Rectangle-friend function (security risk!)
    showBox(r1);
    cout << "r1 " << r1.toString() << endl;
}
//------------------------------------------------------------
void experiment02() {
    //Creating Rectangle objects and references to Rectangles
    //Reviewing pointer syntax and contrasting with object notation
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
//-----------------------------------------------------
void experiment04()
{
    //test operator-overloading
    Rectangle r1(2, 4, "Blue");
    Rectangle r2(2, 4, "Red");

    cout << "r1 " << r1 << endl;
    cout << "r2 " << r2 << endl;

    Rectangle r3;
    cout << "r3 " << r3 << endl;
    r3 = r1 + r2;
    cout << "r3 " << r3 << endl;

}


int main()
{
    //experiment01();
    //experiment02();
    //experiment03();
    experiment04();
    cout << "All done!\n";
}

