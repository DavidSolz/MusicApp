#ifndef _AUDIOEFFECTPIPELINEBUFFER_H
#define _AUDIOEFFECTPIPELINEBUFFER_H

#include "audioBuffer.h"

class AudioEffectPipelineBuffer{
public:
    AudioEffectPipelineBuffer(uint32_t size);
    virtual ~AudioEffectPipelineBuffer();

    virtual void fromAudioBuffer(audioBuffer* buff) = 0;
    virtual void toAudioBuffer(audioBuffer* buff) = 0;

    int32_t* left;
    int32_t* right;

    int16_t getCount();

protected:

    uint16_t count;
    const uint16_t size;
};

#endif