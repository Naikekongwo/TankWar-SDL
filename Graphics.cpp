#include "Graphics.h"
#include "Console.h"
#include <Windows.h>

bool SDL_ADAPTER::run()
{
    if(!Init()) return false;
    if(!Load()) return false;
    // 初始化 和 加载资源 任何一环出现问题即返回 false 然后终结程序。

    bool should_close = false;
    SDL_Event Events;
    while(!should_close)
    {
        while(SDL_PollEvent(&Events))
        {
            switch((Events.type))
            {
                case SDL_QUIT:
                    should_close = true;
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(100);
    }
    CleanUp();
    return true;
}

bool SDL_ADAPTER::Init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        DebugCout("SDL初始化失败。");
        return false;
    }

    window = SDL_CreateWindow(APP_NAME,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,GP_WIDTH,GP_HEIGHT,SDL_WINDOW_SHOWN);
    if(!window)
    {
        DebugCout("SDL窗口创建失败。");
        return false;
    }

    // 设置图标
    iconSurface = SDL_LoadBMP(GP_WINDOW_ICON);
    if(!iconSurface)
    {
        DebugCout("窗口图标设置失败。");
        return false;
    }
    SDL_SetWindowIcon(window,iconSurface);


    winSurface = SDL_GetWindowSurface(window);
    if(!winSurface)
    {
        DebugCout("SDL在获取窗口的表面时候遇到了问题。");
        return false;
    }
    return true;
}

bool SDL_ADAPTER::Load()
{
    return true;
}

void SDL_ADAPTER::CleanUp()
{
    SDL_FreeSurface(winSurface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}