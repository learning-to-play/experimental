// Default initialization example.
#include <iostream>

struct Foo {
    Foo(int value) :
        value1(value) {
            std::cout << "value1 set." << std::endl;
        }
    int value1;
    int value2;
};

Foo foo1(1);


int main() {
    std::cerr << "value1: " << foo1.value1 << std::endl;
    std::cerr << "value2: " << foo1.value2 << std::endl;
}
