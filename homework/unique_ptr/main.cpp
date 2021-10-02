#include <iostream>
#include "uniquePtr.hpp"

void f() { unique_ptr<int> ptr(new int(123)); }

class Point {
   public:
    
    Point(int x, int y) : x(x), y(y) {}
    
    int getX() { return x; }

    private:
    int x;
    int y;
};

int main() {
    f();
    unique_ptr<Point> p(new Point(44, 55));
    std::cout << p->getX()<<std::endl;
    Point* wsk;
    wsk = p.get();
    std::cout<<wsk->getX();
    

    return 0;
}