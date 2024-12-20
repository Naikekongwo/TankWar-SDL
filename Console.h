#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <iostream>
#include <SDL2/SDL.h>
#include "Macro.h"

static void DebugCout(std::string tag)
{
    std::cout<<tag<<std::endl;
    std::cout<<SDL_GetError()<<std::endl;
}

#endif //_CONSOLE_H_