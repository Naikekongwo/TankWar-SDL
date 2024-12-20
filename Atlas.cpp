
#include "ATLAS.h"
#include "Console.h"

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

SDL_Texture* TextureList::Get_Texture(int index)
{
    return textureList.at(index);
}

int TextureList::Push_Back(std::string TexturePath)
{
    SDL_Texture* newTexture;

}

int TextureList::Push_Texture(SDL_Texture* newTexture)
{
    textureList.push_back(newTexture);
    return 0;
}

int TextureList::size()
{
    return textureList.size();
    // 返回内部vector的长度，此长度即为一个材质表内的材质数量
}

Animation::Animation(SDL_Renderer* renderer, SDL_Texture* animeTexture, int row, int column)
{
    this->renderer = renderer;
    frameCount[0] = row;
    frameCount[1] = column;
    frameCounts = row*column;
    // 设置行列上总共的动画数量
    int pWidth,pHeight;
    // if(!SDL_QueryTexture(animeTexture,NULL,NULL,&pWidth,&pHeight))
    // {
    //     DebugCout("获取动画的尺寸时失败。");
    // }
    pWidth = 512;
    pHeight = 512;
    singleFrameSize[0] = pWidth/frameCount[0];
    singleFrameSize[1] = pHeight/frameCount[1];

    SDL_Rect srcRect;
    SDL_Rect dstRect = {0,0,singleFrameSize[0],singleFrameSize[1]};
    // 得到单张贴图的大小 0 为宽度 1 为高度
    animationList = new TextureList();
    for(int i = 0,j=0;i<frameCount[1] & j<frameCount[0];j++)
    {
        SDL_Texture* newTexture;
        newTexture = SDL_CreateTexture(renderer,NULL,NULL,singleFrameSize[0],singleFrameSize[1]);
        SDL_SetRenderTarget(renderer,newTexture);
        srcRect = {i*singleFrameSize[1],j*singleFrameSize[0],(i+1)*singleFrameSize[1],(j+1)*singleFrameSize[0]};
        SDL_RenderCopy(renderer, animeTexture,&srcRect,&dstRect);
        animationList->Push_Texture(newTexture);        
        // 遍历i行,j列
        std::cout<<"正在拆解贴图，当前i="<<i<<",j="<<j<<std::endl;
        if(j==frameCount[0]-1)
        {
            j = -1;
            i++;
            //换行
        }
    }
}

SDL_Rect Animation::getAnimeRect()
{
    return {0,0,singleFrameSize[0],singleFrameSize[1]};
}

SDL_Texture* Animation::onUpdate(Timer time)
{
    int Index = time.GetTime()/(FRAME_SECONDS/frameCounts);
    
    return animationList->Get_Texture(Index);
}

Animation::~Animation()
{
    animationList->~TextureList(); //销毁动画的所有帧
}