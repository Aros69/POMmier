#include "CompleteSquareAreaView.h"

CompleteSquareAreaView::CompleteSquareAreaView(
        const CompleteSquareArea *squareArea1) {
    squareArea = squareArea1;
    sizeX = squareArea->getLength();
    sizeY = squareArea->getWidth();
}

void CompleteSquareAreaView::print(WinTXT &win) {
    // Délimitation de la zone de l'ecosystème

    for (unsigned int y = 1; y < sizeY + 1; ++y) {
        win.print(0, y, '|');
        win.print(sizeX + 1, y, '|');
    }
    for (unsigned int x = 0; x < sizeX + 2; ++x) {
        win.print(x, 0, '_');
        win.print(x, sizeY + 1, '_');
    }
}