#ifndef WINTXT_H
#define WINTXT_H

#include <cassert>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <stdio.h>

using namespace std;

//! \brief une fenêtre texte est un tableau 2D de caractères
class WinTXT {

private:

    int dimx;       //!< \brief largeur
    int dimy;       //!< \brief heuteur
    char *win;      //!< \brief stocke le contenu de la fenêtre dans un tableau 1D mais on y accede en 2D

public:

    WinTXT(int dx, int dy);

    ~WinTXT() {
        delete (win);
        win = nullptr;
    };

    void clear(char c = ' ');

    void print(int x, int y, char c);

    void print(int x, int y, char *c);

    void print(int x, int y, string str);

    void draw(int x = 0, int y = 0);

    void pause();

    char getCh();

};

void termClear();

#endif
