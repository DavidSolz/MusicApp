#ifndef _BALANCEEFFECT_H
#define _BALANCEEFFECT_H

#include "IAudioEffect.h"

class BalanceEffect: public IAudioEffect{
public:
    BalanceEffect();
    ~BalanceEffect();
    void apply(audioBuffer* buff, const audioFileInfo& info);
    void set(float* settings);
    void getSetting(float* settings);
    std::string getName();
private:
    float balance;
};

#endif