#include "VolumeEffect.h"

VolumeEffect::VolumeEffect(){
    volume = 1;
}

VolumeEffect::~VolumeEffect(){

}

void VolumeEffect::apply(AudioEffectPipelineBuffer* buff, const audioFileInfo& info){
    for (uint16_t i = 0; i < buff->getCount(); i++){
        if (i == 0){
            // printf("%x\n", buff->left[i]);
            // printf("%i\n", buff->left[i]);
        }
        buff->left[i] *= volume;
        buff->right[i] *= volume;
        if (i == 0){
            // printf("%x\n", buff->left[i]);
            // printf("%i\n\n", buff->left[i]);
        }
    }
}

void VolumeEffect::set(float* settings){
    volume = *settings;
}

void VolumeEffect::getSetting(float* settings){
    *settings = volume;
}

std::string VolumeEffect::getName(){
    return "volume";
}
