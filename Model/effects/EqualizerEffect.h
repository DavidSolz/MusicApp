#ifndef _EQUALIZER_H
#define _EQUALIZER_H

#include "IAudioEffect.h"

class EqualizerEffect: public IAudioEffect{
public:
    EqualizerEffect();
    ~EqualizerEffect();
    void apply(AudioEffectPipelineBuffer* buff, const audioFileInfo& info);
    void set(float* settings);
    void getSetting(float* settings);
    std::string getName();
private:
    float* eqValues;
    float* eqFreq;
    uint eqBands;
};
#endif