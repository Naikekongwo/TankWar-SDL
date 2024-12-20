#include "Graphics.h"
#include "Console.h"
#include "Atlas.h"

bool SDL_ADAPTER::run()
{
    if(!Init()) return false;
    if(!Load()) return false;
    // 初始化 和 加载资源 任何一环出现问题即返回 false 然后终结程序。

    loop();
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

    // window = SDL_CreateWindow(APP_NAME,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,GP_WIDTH,GP_HEIGHT,SDL_WINDOW_SHOWN);
    // if(!window)
    // {
    //     DebugCout("SDL窗口创建失败。");
    //     return false;
    // } 已经废弃，并合并进入了CreateWindowAndRenderer


    // winSurface = SDL_GetWindowSurface(window);
    // if(!winSurface)
    // {
    //     DebugCout("SDL在获取窗口的表面时候遇到了问题。");
    //     return false;
    // } 已经废弃了，转而使用硬件渲染

    if(SDL_CreateWindowAndRenderer(GP_WIDTH,GP_HEIGHT,NULL,&window,&renderer)!=0)
    {
        DebugCout("在创建窗口和渲染器时失败。");
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
    
    return true;
}

bool SDL_ADAPTER::Load()
{
    
    return true;
}


bool SDL_ADAPTER::loop()
{
    bool should_close = false;
    SDL_Event Events;

    Timer time;

    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderDrawPoint( renderer, 100, 100 );

    // Update window
    SDL_RenderPresent( renderer );

    SDL_Surface* animeSurface = SDL_LoadBMP("resources//animate_sample.bmp");
    SDL_Texture* animeTexture = SDL_CreateTextureFromSurface(renderer,animeSurface);

    SDL_FreeSurface(animeSurface);
    
    Animation anime1(renderer,animeTexture,2,2);
    
    while(!should_close)
    {
        while(SDL_PollEvent(&Events))
        {
            switch((Events.type))
            {
                case SDL_QUIT:
                    should_close = true;
                    return true;
                    break;
                default:
                    break;
            }
        }
        SDL_Rect dstRect = {0,0,256,256};
        SDL_Texture* now = anime1.onUpdate(time);
        SDL_RenderCopy(renderer, now, &dstRect, &dstRect);
        
        SDL_RenderPresent( renderer );
        SDL_Delay(6000/FRAME_SECONDS);
        time.OnUpdate();
    }
    return false;
}

void SDL_ADAPTER::CleanUp()
{
    // SDL_FreeSurface(winSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}