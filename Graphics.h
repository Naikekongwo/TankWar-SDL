#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_


#include <SDL2/SDL.h>
#include "Macro.h"
#include "Atlas.h"
#include "Timer.h"

class SDL_ADAPTER {
    public:
    bool run(); //主函数
    bool Init(); //初始化
    bool Load(); //加载资源
    bool loop(); // 主循环
    void CleanUp(); //结束回收资源

    private:
    SDL_Window* window;
    // SDL_Surface* winSurface; 废弃的，因为我们放弃了surface渲染使用硬件加速。
    SDL_Renderer* renderer; // 渲染器
    SDL_Surface* iconSurface;
    TextureList textureList;
    
};

class Camera {
    public:
};

#endif //_GRAPHICS_H_