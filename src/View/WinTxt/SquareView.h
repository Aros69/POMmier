#ifndef POMMIER_SQUAREVIEW_H
#define POMMIER_SQUAREVIEW_H


#include "GenericView.h"
#include "../../Model/World/Square.h"

class SquareView : public GenericView {
private:
    Square *square;
    // TODO add sky, vegetation and ground view

public:
    SquareView(Square *square1, unsigned int offsetX, unsigned int offsetY);

    void setSquare(Square *square1) { square = square1; }

    void print(WinTXT &win) override;
};


#endif //POMMIER_SQUAREVIEW_H
