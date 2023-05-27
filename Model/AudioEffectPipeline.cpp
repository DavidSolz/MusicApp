#include "AudioEffectPipeline.h"


AudioEffectPipeline::AudioEffectPipeline():effectCount(3){
    effects = new IAudioEffect*[effectCount];
    effects[0] = new VolumeEffect();
    effects[1] = new BalanceEffect();
    effects[2] = new EqualizerEffect();
}

AudioEffectPipeline::~AudioEffectPipeline(){
    for (uint i = 0; i < effectCount; i++){
        delete effects[i];
    }
    delete[] effects;
}

void AudioEffectPipeline::apply(audioBuffer* buff, const audioFileInfo& info){
    for (uint i = 0; i < effectCount; i++){
        effects[i]->apply(buff, info);
    }
}

void AudioEffectPipeline::setEffect(std::string effectId, float* settings){
    for (uint i = 0; i < effectCount; i++){
        if (effects[i]->getName() == effectId){
            effects[i]->set(settings);
            break;
        }
    }
}

void AudioEffectPipeline::getEffectSettings(std::string effectId, float* settings){
    for (uint i = 0; i < effectCount; i++){
        if (effects[i]->getName() == effectId){
            effects[i]->getSetting(settings);
            break;
        }
    }
}