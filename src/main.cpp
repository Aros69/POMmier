#include <iostream>
#include "Model/World/World.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    //World w1;
    World w2(50, 50);

    w2.getSquare(3,20);

    return 0;
}