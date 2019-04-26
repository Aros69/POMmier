#include <iostream>
#include "Model/World/World.h"
#include "Controller/WorldController.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    //World w1;
    WorldController w2(50, 50);

    w2.getSquare(3,20);

    return 0;
}