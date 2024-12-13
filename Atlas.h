#ifndef _ATLAS_H_
#define _ATLAS_H_


#include <vector>
#include <SDL2/SDL.h>



class TextureList
{
    public:
    TextureList() = default; // 构造函数
    ~TextureList(); // 析构函数
    
    private:
    std::vector<SDL_Texture*> textureList;
};

#endif //_ATLAS_H_