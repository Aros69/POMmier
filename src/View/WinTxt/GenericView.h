#ifndef POMMIER_GENERICVIEW_H
#define POMMIER_GENERICVIEW_H

#include "../../../include/WinTxt/winTxt.h"

class GenericView {
protected:
    unsigned int offsetX = 0;
    unsigned int offsetY = 0;

public:
    GenericView(unsigned int offsetX, unsigned int offsetY) {
        this->offsetX = offsetX;
        this->offsetY = offsetY;
    }

    virtual void print(WinTXT &win) = 0;
};


#endif //POMMIER_GENERICVIEW_H
