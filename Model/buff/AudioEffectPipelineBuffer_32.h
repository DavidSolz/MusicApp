#ifndef _IAUDIOEFFECTPIPELINEBUFFER_32_H
#define _IAUDIOEFFECTPIPELINEBUFFER_32_H

#include "AudioEffectPipelineBuffer.h"

class AudioEffectPipelineBuffer_32: public AudioEffectPipelineBuffer{
public:
    using AudioEffectPipelineBuffer::AudioEffectPipelineBuffer;

    void fromAudioBuffer(audioBuffer* buff);
    void toAudioBuffer(audioBuffer* buff);
};

#endif