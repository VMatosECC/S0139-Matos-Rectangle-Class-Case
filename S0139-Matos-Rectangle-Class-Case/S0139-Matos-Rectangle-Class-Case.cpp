

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

void experiment01()
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
}
//------------------------------------------------------------
void experiment02() {
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
    //NEEDS RULE OF THREE! 
    Rectangle r1(11, 11, "Pink");
    cout << "r1 " << r1.toString() << endl;
}

int main()
{
    //experiment01();
    //experiment02();
    experiment03();
    cout << "All done!\n";
}

