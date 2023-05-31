#ifndef _AUDIOEFFECTPIPELINE_H
#define _AUDIOEFFECTPIPELINE_H

#include "buff/AudioEffectPipelineBuffer.h"
#include "buff/AudioEffectPipelineBufferBuilder.h"
#include "effects/IAudioEffect.h"

#include "effects/VolumeEffect.h"
#include "effects/BalanceEffect.h"
#include "effects/EqualizerEffect.h"

class AudioEffectPipeline {
public:
    AudioEffectPipeline();
    ~AudioEffectPipeline();
    void init(audioBuffer* buff, audioFileInfo& info);
    void apply(audioBuffer* buff, const audioFileInfo& info);
    void setEffect(std::string effectId, float* settings);
    void getEffectSettings(std::string effectId, float* settings);
private:
    IAudioEffect** effects;
    const unsigned int effectCount;
    AudioEffectPipelineBuffer* buffer;
    AudioEffectPipelineBufferBuilder* bufferBuilder;
};

#endif