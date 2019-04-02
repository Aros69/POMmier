#ifndef POMMIER_SIMULATIONTXT_H
#define POMMIER_SIMULATIONTXT_H

#ifdef _WIN32
#include <windows.h>
#else

#include <unistd.h>

#endif // WIN32

#include <chrono>

#include "../../../include/WinTxt/winTxt.h"
#include "../../Controller/WorldController.h"
#include "CompleteSquareAreaView.h"
#include "SquareView.h"

// Should : Initialize window, create controller, prepare views, run simulation
class SimulationTxt {
private:
    unsigned int squareIndexX = 0, squareIndexY = 0;
    WorldController *worldController;
    CompleteSquareAreaView *worldView;
    SquareView *squareView;
    //TODO Add views (SquareArea and Square)
    WinTXT *window;

    void update();

    void printEnteteWindow() const;

    void printSimulation() const;

public:

    SimulationTxt();

    ~SimulationTxt();

    void startSimulation();
};


#endif //POMMIER_SIMULATIONTXT_H
