#include <iostream>
using namespace std;

class Shape {  // abstract class
public:
    virtual float getArea() = 0;  // pure virtual function, it makes this class as abstract class

    virtual void show() {  // virtual function
        cout << "Shape class" << endl;
    }
};

class Rectangle : public Shape {
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    float getArea() {
        return length * breadth;
    }

    void show() {
        cout << "Rectangle class" << endl;
    }
};

class Circle : public Shape {
    int radius;

public:
    Circle(int r) {
        radius = r;
    }

    float getArea() {
        return 3.14 * radius * radius;
    }

    void show() {
        cout << "Circle class" << endl;
    }
};

int main() {
    Shape* ptr = NULL;

    Rectangle* r = new Rectangle(4, 5);
    cout << r->getArea() << endl;
    ptr = r;  // base class pointer pointing to derived class object
    cout << ptr->getArea() << endl;

    Circle* c = new Circle(7);
    cout << c->getArea() << endl;
    ptr = c;  // base class pointer pointing to derived class object
    cout << ptr->getArea() << endl;

    return 0;
}

/*
Polymorphism: Same thing exhibits different behaviour based on different context.

"Function Overloading" & "Operator Overloading" are the example of "Compile Time Polymorphism".

"Function Overriding" & "Virtual Functions" are the example of "Runtime Polymorphism".
Based on the which class/object is pointed by a pointer, then appropriate function is called, it is called dynamic binding.

"Pure Virtual Function" is declared with "=0".
A class having pure virtual function is known as Abstract Class. Abstract class cannot be instantiated.
*/
