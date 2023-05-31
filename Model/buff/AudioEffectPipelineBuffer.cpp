#include "AudioEffectPipelineBuffer.h"

AudioEffectPipelineBuffer::AudioEffectPipelineBuffer(uint32_t size):
    size(size){
    left = new int32_t[size];
    right = new int32_t[size];
}

AudioEffectPipelineBuffer::~AudioEffectPipelineBuffer(){
    delete[] left;
    delete[] right;
}

int16_t AudioEffectPipelineBuffer::getCount(){
    return count;
}