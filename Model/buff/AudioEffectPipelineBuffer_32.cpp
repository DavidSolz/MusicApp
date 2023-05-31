#include "AudioEffectPipelineBuffer_32.h"

void AudioEffectPipelineBuffer_32::fromAudioBuffer(audioBuffer* buff){
    uint16_t l = 0;
    for (uint16_t i = 0,r = 0; i < buff->count;){
        left[l] = buff->buff[i++];
        left[l] += buff->buff[i++] << 8;
        left[l] += buff->buff[i++] << 16;
        left[l++] += buff->buff[i++] << 24;

        right[r] = buff->buff[i++];
        right[r] += buff->buff[i++] << 8;
        right[r] += buff->buff[i++] << 16;
        right[r++] += buff->buff[i++] << 24;
    }
    count = l;
}

void AudioEffectPipelineBuffer_32::toAudioBuffer(audioBuffer* buff){
    for (uint16_t i = 0,l = 0,r = 0; i < buff->count;){
        buff->buff[i++] = left[l];
        buff->buff[i++] = left[l] << 8;
        buff->buff[i++] = left[l] << 16;
        buff->buff[i++] = left[l++] << 24;

        buff->buff[i++] = right[r];
        buff->buff[i++] = right[r] << 8;
        buff->buff[i++] = right[r] << 16;
        buff->buff[i++] = right[r++] << 24;
    }
}
