#include <iostream>

using namespace std;

class A {
protected:
    int x;
public:
    A() { x = 1000; }

    virtual void print() {
        cout << "x=" << x << endl;
    }
};

class B : public A {
    int y;
public:
    B() { y = 2000; }

    void print(int) {
        cout << "virtual function overloading" << endl;
    }
};

class C : public A {
    int z;
public:
    C() { z = 3000; }
};

int main() {
    A a, *pa;
    B b;
    C c;
    a.print();
//    b.print();
    b.print(0);
    c.print();
    pa = &a;
    pa->print();
    pa = &b;
    pa->print();
//    pa->print(0);
    pa = &c;
    pa->print();
    return 0;
}