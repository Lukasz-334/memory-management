#include <iostream>
#include "uniquePtr.hpp"
#include "Point.hpp"

void f() {
    unique_ptr<int> ptr(new int(123));
}






    

void resetTest() {
    unique_ptr<Point> p(new Point(88, 55));
    std::cout << p->getX() << std::endl;
    std::cout << p.get() << std::endl;

    p.reset(new Point(22, 88));

    std::cout << p->getX() << std::endl;
    std::cout << p.get() << std::endl;

    p.reset();
    if (!p.get()) {
        std::cout << "p points nullptr" << std::endl;
    }
    p.reset(new Point(72, 88));
    
}

int main() {
    
    
    resetTest();

    return 0;
}