#ifndef _VOLUMEEFFECT_H
#define _VOLUMEEFFECT_H

#include "IAudioEffect.h"

class VolumeEffect: public IAudioEffect{
public:
    VolumeEffect();
    ~VolumeEffect();
    void apply(AudioEffectPipelineBuffer* buff, const audioFileInfo& info);
    void set(float* settings);
    void getSetting(float* settings);
    std::string getName();
private:
    float volume;
};

#endif