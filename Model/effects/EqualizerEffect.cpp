#include "EqualizerEffect.h"


EqualizerEffect::EqualizerEffect(){
    eqBands = 3;
    eqValues = new float[eqBands];
    eqFreq = new float[eqBands+1];

    for (uint i = 0; i < eqBands; i++){
        eqValues[i] = 0;
    }

    eqFreq[0] = 0;
    eqFreq[1] = 200;
    eqFreq[2] = 800;
    eqFreq[3] = 20000;
}

EqualizerEffect::~EqualizerEffect(){
    delete[] eqValues;
    delete[] eqFreq;
}

void EqualizerEffect::apply(AudioEffectPipelineBuffer* buff, const audioFileInfo& info){

}

void EqualizerEffect::set(float* settings){
    for (uint i = 0; i < 3; i++){
        eqValues[i] = settings[i];
    }
}

void EqualizerEffect::getSetting(float* settings){
    for (uint i = 0; i < 3; i++){
        settings[i] = eqValues[i];
    }
}

std::string EqualizerEffect::getName(){
    return "equalizer";
}
