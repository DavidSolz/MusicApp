#include "AudioEffectPipeline.h"

AudioEffectPipeline::AudioEffectPipeline():effectCount(3){
    bufferBuilder = new AudioEffectPipelineBufferBuilder(buffer);
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
    delete bufferBuilder;
}

void AudioEffectPipeline::init(audioBuffer* buff, audioFileInfo& info){
    bufferBuilder->checkCompatybility(buff, info);
}

void AudioEffectPipeline::apply(audioBuffer* buff, const audioFileInfo& info){
    this->buffer->fromAudioBuffer(buff);
    for (uint i = 0; i < effectCount; i++){
        effects[i]->apply(this->buffer, info);
    }
    this->buffer->toAudioBuffer(buff);
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