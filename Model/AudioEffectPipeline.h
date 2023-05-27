#ifndef _AUDIOEFFECTPIPELINE_H
#define _AUDIOEFFECTPIPELINE_H

#include "IAudioEffect.h"

#include "VolumeEffect.h"
#include "BalanceEffect.h"
#include "EqualizerEffect.h"

class AudioEffectPipeline {
public:
    AudioEffectPipeline();
    ~AudioEffectPipeline();
    void apply(audioBuffer* buff, const audioFileInfo& info);
    void setEffect(std::string effectId, float* settings);
    void getEffectSettings(std::string effectId, float* settings);
private:
    IAudioEffect** effects;
    const uint effectCount;
};

#endif