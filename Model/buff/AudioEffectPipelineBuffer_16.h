#ifndef _IAUDIOEFFECTPIPELINEBUFFER_16_H
#define _IAUDIOEFFECTPIPELINEBUFFER_16_H

#include "AudioEffectPipelineBuffer.h"

class AudioEffectPipelineBuffer_16: public AudioEffectPipelineBuffer{
public:
    using AudioEffectPipelineBuffer::AudioEffectPipelineBuffer;

    void fromAudioBuffer(audioBuffer* buff);
    void toAudioBuffer(audioBuffer* buff);
};

#endif
