#ifndef _AUDIOEFFECT_H
#define _AUDIOEFFECT_H

#include "audioBuffer.h"
#include "audioFileInfo.h"

class IAudioEffect{
public:
    // virtual ~IAudioEffect() = 0;
    virtual void apply(audioBuffer* buff, const audioFileInfo& info) = 0;
    virtual void set(float* settings) = 0;
    virtual void getSetting(float* settings) = 0;
    virtual std::string getName() = 0;
};

#endif