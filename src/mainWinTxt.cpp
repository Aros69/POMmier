#include <iostream>
#include "View/WinTxt/SimulationTxt.h"

// TODO Check if getPartOfSquareArea is Memory Leak Free
int main() {
    std::cout << "Stating txt simulation !\n";

    /*for(int i=0;i<101;++i){
        for(int j=0;j<101;++j){
            World world(i,j);
            SquareArea* sqr = world.getPartOfSquareArea(2, 2, 4);
            delete sqr;
        }
    }*/

    //SimulationTxt simulation;
    //simulation.startSimulation();

    std::cout << "Bye World !\n";
    return 0;
}