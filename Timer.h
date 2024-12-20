#ifndef _TIMER_H_
#define _TIMER_H_

#include "Macro.h"

class Timer
{
    public:
    Timer() = default;

    int OnUpdate()
    {
        eTime = (eTime==FRAME_SECONDS-1)?0:(eTime+1);
        // 到119帧就归零
        return eTime;
    }

    int GetTime()
    {
        return eTime;
    }
    
    private:
    int eTime = 0;
};


#endif //_TIMER_H_