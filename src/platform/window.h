#ifndef EMBER_PLATFORM_WINDOW_H
#define EMBER_PLATFORM_WINDOW_H
#include "ert/types.h"
b8 ember_windowInit();
b8 ember_windowShouldClose();
void ember_windowPollEvents();
void ember_windowClose();
b8 ember_windowShutdown();
#endif
