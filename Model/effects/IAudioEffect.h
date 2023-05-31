#ifndef _AUDIOEFFECT_H
#define _AUDIOEFFECT_H

#include "../buff/AudioEffectPipelineBuffer.h"
#include "../buff/audioFileInfo.h"

class IAudioEffect{
public:
    //virtual ~IAudioEffect() = 0;
    virtual void apply(AudioEffectPipelineBuffer* buff, const audioFileInfo& info) = 0;
    virtual void set(float* settings) = 0;
    virtual void getSetting(float* settings) = 0;
    virtual std::string getName() = 0;
};

#endif