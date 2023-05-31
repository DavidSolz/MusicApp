#ifndef _IAUDIOEFFECTPIPELINEBUFFER_8_H
#define _IAUDIOEFFECTPIPELINEBUFFER_8_H

#include "AudioEffectPipelineBuffer.h"

class AudioEffectPipelineBuffer_8: public AudioEffectPipelineBuffer{
public:
    using AudioEffectPipelineBuffer::AudioEffectPipelineBuffer;

    void fromAudioBuffer(audioBuffer* buff);
    void toAudioBuffer(audioBuffer* buff);
};
#endif