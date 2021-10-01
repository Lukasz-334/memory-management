#include <iostream>
#include <memory>
#include <vector>

void f() {
    int* p = new int(5);
    std::cout << *p << std::endl;
    delete p;
}

void f2() {
    std::unique_ptr<int> p(new int(22));
    std::cout << *p << std::endl;

    std::unique_ptr<int> wsk(std::make_unique<int>(33));
    *wsk = 12;
    std::cout << *wsk << std::endl;
}

int main() {
    f2();
}
