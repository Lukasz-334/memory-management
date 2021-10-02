#include <iostream>
#include "uniquePtr.hpp"



class Point {
public:
    Point(int x, int y)
        : x(x), y(y) {}
    int x;
    int y;
    int getX() { return x; }
};

void f() {
    unique_ptr<int> ptr(new int(123));
}

void operatorArrowTest() {
    unique_ptr<Point> p(new Point(17, 55));

    std::cout << p->getX() << std::endl;
}

void getTest() {
    unique_ptr<Point> p(new Point(44, 55));
    Point* wsk;
    wsk = p.get();
    std::cout << wsk->x << std::endl;
    std::cout << p->getX() << std::endl;
}

void releaseTest() {
    unique_ptr<Point> p(new Point(88, 55));
    Point* wsk;
    wsk = p.release();
    if (p.get() == nullptr) {
        std::cout << "p points to nullptr " << std::endl;
    }
    std::cout << wsk->x << std::endl;
    
    delete wsk;
}

int main() {
   operatorArrowTest();
   getTest();
   releaseTest();

    return 0;
}