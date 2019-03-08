#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include "../../../include/WinTxt/winTxt.h"
#include "../../Controller/WorldController.h"


void txtAff(WinTXT &win, const WorldController &world) {

    unsigned int sizeX = world.getWorld().getCompleteSquareArea()->getLength();
    unsigned int sizeY = world.getWorld().getCompleteSquareArea()->getLength();

    win.clear();

    // Délimitation de la zone de l'ecosystème
    for (unsigned int y = 1; y < sizeY + 1; ++y) {
        win.print(0, y, '|');
        win.print(sizeX + 1, y, '|');
    }
    for (unsigned int x = 0; x < sizeX + 2; ++x) {
        win.print(x, 0, '_');
        win.print(x, sizeY + 1, '_');
    }
    // Affichage de l'ecosysteme
    int realX, realY;
    for (unsigned int y = 0; y < sizeY; ++y) {
        for (unsigned int x = 0; x < sizeX; ++x) {
            realY = y + 1;
            realX = x + 1;
            switch (world.getTileType(x, y)) {
                case '0' : {
                    win.print(realX, realY, ' ');
                    break;
                }
                case 'g' : {
                    win.print(realX, realY, 'w');
                    break;
                }
                default: {
                    win.print(x, y, '#');
                    break;
                }
            }
        }

    }
    win.draw();
}

void txtBoucle(World &world) {
    // Creation d'une nouvelle fenetre en mode texte
    // => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win(world.getLine() + 2, world.getColomn() + 2);
    bool ok = true;
    int c;
    unsigned int timer = 0;
    do {
        txtAff(win, world);

#ifdef _WIN32
        Sleep(100);
#else
        usleep(100000);
#endif // WIN32
        c = win.getCh();
        switch (c) {
            case 'p': {
                ok = false;
                break;
            }
            case '\e': {
                ok = false;
                break;
            }
        }
    } while (ok);

}
