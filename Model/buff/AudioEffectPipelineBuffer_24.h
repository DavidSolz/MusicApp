#ifndef _IAUDIOEFFECTPIPELINEBUFFER_24_H
#define _IAUDIOEFFECTPIPELINEBUFFER_24_H

#include "AudioEffectPipelineBuffer.h"

class AudioEffectPipelineBuffer_24: public AudioEffectPipelineBuffer{
public:
    using AudioEffectPipelineBuffer::AudioEffectPipelineBuffer;

    void fromAudioBuffer(audioBuffer* buff);
    void toAudioBuffer(audioBuffer* buff);
};

#endif