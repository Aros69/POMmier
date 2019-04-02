#ifndef POMMIER_COMPLETESQUAREAREAVIEW_H
#define POMMIER_COMPLETESQUAREAREAVIEW_H

#include "GenericView.h"
#include "../../Model/World/SquareArea.h"

class CompleteSquareAreaView : public GenericView {
private:
    // Should not be deleted in this class because it's a pointer to the model element
    const CompleteSquareArea *squareArea;
    unsigned int sizeX, sizeY;

public:
    CompleteSquareAreaView() = delete;

    CompleteSquareAreaView(const CompleteSquareArea *squareArea1,
                           unsigned int offsetX,
                           unsigned int offsetY);

    unsigned int getSizeX() const { return sizeX; };

    unsigned int getSizeY() const { return sizeY; };

    void print(WinTXT &win) override;

};


#endif //POMMIER_COMPLETESQUAREAREAVIEW_H
