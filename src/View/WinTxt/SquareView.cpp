#include "SquareView.h"

SquareView::SquareView(Square *square1, unsigned int offsetX,
                       unsigned int offsetY) : GenericView(offsetX, offsetY) {
    square = square1;
}

void SquareView::print(WinTXT &win) {
    std::string sky = "Sky Detail :";
    std::string vegetation = "Vegetation Detail :";
    std::string ground = "Ground Detail :";
    win.print(offsetX, offsetY, sky);
    win.print(offsetX, offsetY + 5, vegetation);
    win.print(offsetX, offsetY + 15, ground);
}