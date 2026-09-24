#ifndef EMBER_RENDERER_H
#define EMBER_RENDERER_H
#include "ert/types.h"
typedef void (*ember_GameLogicFunction)(f64 dt);
b8 ember_rendererInit();
b8 ember_rendererMainLoop(ember_GameLogicFunction);
b8 ember_rendererShutdown();
#endif
