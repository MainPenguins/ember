#include "platform/input.h"
#include <SDL3/SDL.h>
#include <string.h>
static int s_keyCount = SDL_SCANCODE_COUNT;
static b8 s_keys[SDL_SCANCODE_COUNT] = {0};
static b8 s_keysPrev[SDL_SCANCODE_COUNT] = {0};
b8 ember_inputInit()
{
    memset(s_keys,0,s_keyCount);
    memset(s_keysPrev,0,s_keyCount);
    return true;
}
b8 ember_inputShutdown()
{
    memset(s_keys,0,s_keyCount);
    memset(s_keysPrev,0,s_keyCount);
    return true;
}
void ember_inputUpdate()
{
    memcpy(s_keysPrev,s_keys,s_keyCount);
    const b8* keystates = SDL_GetKeyboardState(&s_keyCount);
    memcpy(s_keys,keystates,s_keyCount);
}
b8 ember_inputIsKeyDown(sz64 index)
{
    return s_keys[index];
}
b8 ember_inputIsKeyUp(sz64 index)
{
    return !s_keys[index];
}
b8 ember_inputIsKeyPressed(sz64 index)
{
    return s_keys[index] && !s_keysPrev[index];
}
b8 ember_inputIsKeyHeld(sz64 index)
{
    return s_keys[index] && s_keysPrev[index];
}
b8 ember_inputIsKeyReleased(sz64 index)
{
    return !s_keys[index] && s_keysPrev[index];
}
