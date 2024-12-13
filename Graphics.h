#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_


#include <SDL2/SDL.h>
#include "Macro.h"

class SDL_ADAPTER {
    public:
    bool run(); //主函数
    bool Init(); //初始化
    bool Load(); //加载资源
    void CleanUp(); //结束回收资源

    private:
    SDL_Window* window;
    SDL_Surface* winSurface;

    SDL_Surface* iconSurface;
    
};

class Camera {
    public:
};

#endif //_GRAPHICS_H_