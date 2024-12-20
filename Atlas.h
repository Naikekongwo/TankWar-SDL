#ifndef _ATLAS_H_
#define _ATLAS_H_

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "Timer.h"



class TextureList
{
    public:
    TextureList() = default; // 构造函数
    ~TextureList(); // 析构函数

    SDL_Texture* Get_Texture(int index);

    int Push_Back(std::string TexturePath); // 添加材质的函数
    int Push_Texture(SDL_Texture* newTexture);
    int size(); // 获取长度
    
    private:
    std::vector<SDL_Texture*> textureList;
};

class Animation
{
    public:
    Animation(SDL_Renderer* renderer, SDL_Texture* animeTexture, int row, int column); // 构造函数
    ~Animation(); // 析构函数

    SDL_Texture* onUpdate(Timer time);
    SDL_Rect getAnimeRect();

    private:
    SDL_Renderer* renderer;
    TextureList* animationList; // 内部的动画图集
    int frameCount[2];
    int frameCounts;
    int singleFrameSize[2];
    
};

#endif //_ATLAS_H_