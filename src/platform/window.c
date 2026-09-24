#include "platform/window.h"
#include <SDL3/SDL_events.h>
#include <glad/glad.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include "emberdef.h"
static SDL_Window* s_window = {0};
static SDL_Event s_event = {0};
static b8 s_windowShouldClose = false;

b8 ember_windowInit()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        return false;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    s_window = SDL_CreateWindow(EMBER_TITLE, EMBER_WIDTH, EMBER_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (!s_window)
    {
        return false;
    }
    if (!SDL_GL_CreateContext(s_window))
    {
        return false;
    }
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        return false;
    }
    return true;
}
b8 ember_windowShouldClose()
{
    return s_windowShouldClose;
}
void ember_windowPollEvents()
{
    while (SDL_PollEvent(&s_event))
    {
        if (s_event.type == SDL_EVENT_WINDOW_RESIZED)
        {
            if (s_event.window.data1 == 0 || s_event.window.data2 == 0)
            {
                glViewport(0, 0, EMBER_WIDTH, EMBER_HEIGHT);
            }
            else
            {
                glViewport(0, 0, s_event.window.data1, s_event.window.data2);
            }
        }
    }
}
void ember_windowClose()
{
    s_windowShouldClose = true;
}
b8 ember_windowShutdown()
{
    if (s_window)
        SDL_DestroyWindow(s_window);
    SDL_Quit();
    return true;
}
