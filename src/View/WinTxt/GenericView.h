#ifndef POMMIER_GENERICVIEW_H
#define POMMIER_GENERICVIEW_H

#include "../../../include/WinTxt/winTxt.h"


class GenericView {
public:
    virtual void print(WinTXT &win) = 0;
};


#endif //POMMIER_GENERICVIEW_H
