#ifndef JEUTXT_H
#define JEUTXT_H

#ifdef _WIN32
#include <windows.h>
#else

#include <unistd.h>

#endif // WIN32

#include <chrono>
#include "../../../include/WinTxt/winTxt.h"
#include "../../Model/World/World.h"

void txtAff(WinTXT &win, const World &world);

void txtBoucle(World &world);

#endif // JEUTXT_HHello
