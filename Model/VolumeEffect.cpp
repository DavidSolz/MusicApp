#include "VolumeEffect.h"

VolumeEffect::VolumeEffect(){
    volume = 1;
}

VolumeEffect::~VolumeEffect(){

}

void VolumeEffect::apply(audioBuffer* buff, const audioFileInfo& info){
    for (uint32_t i = 0; i < buff->count; i++){
        buff->buff[i] = char(buff->buff[i])*volume;
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
