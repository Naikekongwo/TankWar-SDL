#ifndef _CORE_H_
#define _CORE_H_


#include <SDL2/SDL.h>
#include "Union.h" // 链接库 头文件

class GAME_CORE {
    // 和窗口的主要的交互类
    public:
    bool Run(); //主函数
    bool Init(); //初始化
    bool Load(); //加载资源
    bool OnUpdate(); // 刷新
    bool MainLoop(); // 主循环
    void CleanUp(); //结束回收资源

    private:
    SDL_Window* window; // 窗口句柄
    SDL_Renderer* renderer; // 渲染器
    Timer* time;  // 内部计时器
};

#endif //_CORE_H_