#include "Union.h"

// GAME_CORE 部分

bool GAME_CORE::Run()
{
    if(!Init()) return false;
    if(!Load()) return false;
    // 初始化 和 加载资源 任何一环出现问题即返回 false 然后终结程序。

    MainLoop();
    CleanUp();
    return true;
}

bool GAME_CORE::Init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        DebugCout("SDL初始化失败。");
        return false;
    }

    if(SDL_CreateWindowAndRenderer(GP_WIDTH,GP_HEIGHT,SDL_RENDERER_ACCELERATED,&window,&renderer)!=0)
    {
        DebugCout("在创建窗口和渲染器时失败。");
        return false;
    }

    SDL_Surface* iconSurface = SDL_LoadBMP(GP_WINDOW_ICON);
    if(!iconSurface)
    {
        DebugCout("窗口图标设置失败。");
        return false;
    }

    SDL_SetWindowIcon(window,iconSurface); // 设置图标
    SDL_SetWindowTitle(window,APP_NAME); // 设置标题

    time = new Timer(FRAME_SECONDS); //初始化计时器
    
    return true;
}

bool GAME_CORE::Load()
{
    return true;
}


bool GAME_CORE::OnUpdate()
{
    time->OnUpdate(); //计时器进一帧
    // DebugCout(std::to_string(time->GetTime()));
    return true;
}

bool GAME_CORE::MainLoop()
{
    bool should_close = false;
    SDL_Event Events;

    // 显示 renderer
    SDL_RenderPresent( renderer );

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
        SDL_RenderPresent( renderer );
        SDL_Delay(1000/FRAME_SECONDS);
    }
    return false;
}

void GAME_CORE::CleanUp()
{
    // SDL_FreeSurface(winSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}