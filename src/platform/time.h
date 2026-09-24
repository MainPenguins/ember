#ifndef EMBER_PLATFORM_WINDOW_TIME_H
#define EMBER_PLATFORM_WINDOW_TIME_H
#include "ert/types.h"
b8 ember_timeInit();
b8 ember_timeShutdown();
void ember_timeUpdate();
f64 ember_timeGetDeltaTime();
f64 ember_timeGetRealTime();
f64 ember_timeGetGameTime();
void ember_timePauseGameTime();
void ember_timeScaleGameTime(f64 scale);
#endif
