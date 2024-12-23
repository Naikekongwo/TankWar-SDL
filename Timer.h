#ifndef _TIMER_H_
#define _TIMER_H_

#include "Macro.h"

class Timer
{
    public:
    // 构造函数
    Timer(int frameSeconds)
    {
        eTime = 0;
        this->frameSeconds = frameSeconds;
    }

    int OnUpdate()
    {
        eTime = (eTime==FRAME_SECONDS-1)?0:(eTime+1);
        // 到119帧就归零
        return eTime;
    }

    // 获取时间
    int GetTime()
    {
        return eTime;
    }

    // 设置时间
    void SetTime(int eTime)
    {
        this->eTime = eTime;
    }
    
    private:
    int eTime,frameSeconds;
    // eTime为一秒内现在的帧数, frameSeconds为当前帧率上限，则一秒内帧率
};


#endif //_TIMER_H_