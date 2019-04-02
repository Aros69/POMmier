#include "CompleteSquareAreaView.h"

CompleteSquareAreaView::CompleteSquareAreaView(
        const CompleteSquareArea *squareArea1, unsigned int offsetX,
        unsigned offsetY) : GenericView(offsetX, offsetY) {
    squareArea = squareArea1;
    sizeX = squareArea->getLength();
    sizeY = squareArea->getWidth();
}

void CompleteSquareAreaView::print(WinTXT &win) {
    // Délimitation de la zone de l'ecosystème
    for (unsigned int y = 1; y < sizeY + 1; ++y) {
        win.print(offsetX + 0, offsetY + y, '|');
        win.print(offsetX + sizeX + 1, offsetY + y, '|');
    }
    for (unsigned int x = 0; x < sizeX + 2; ++x) {
        win.print(offsetX + x, offsetY + 0, '_');
        win.print(offsetX + x, offsetY + sizeY + 1, '_');
    }
}