
#include "ATLAS.h"

TextureList::~TextureList()
{
    for(SDL_Texture* texture : textureList)
    {
        SDL_DestroyTexture(texture);
    }
    textureList.clear();
    // 遍历所有 texture 并逐个销毁
    // 最后直接清空 vector
}

