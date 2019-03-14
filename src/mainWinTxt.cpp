#include <iostream>
#include <random>
#include "View/WinTxt/SimulationTxt.h"

int main() {
    std::cout << "Stating txt simulation !\n"
              << "For avoiding view bugs, "
              << "this windows should be in fullscreen.\n"
              << "After you put this window in full screen, "
              << "you can press enter key to start.\n"
              << "Press esc or 'p' during the simulation to stop it.\n";

    std::getchar();

    SimulationTxt simulation;
    simulation.startSimulation();

    std::cout << "Bye World !\n";
    return 0;
}