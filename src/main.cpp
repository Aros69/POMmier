#include <iostream>
#include "../include/World/World.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    //World w1;
    World w2(50, 50);

    w2.getPartOfSquareArea(4,4,2);

    return 0;
}