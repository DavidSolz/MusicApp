#include "AudioEffectPipelineBuffer_8.h"
#include <cstdint>

void AudioEffectPipelineBuffer_8::fromAudioBuffer(audioBuffer* buff){
    uint16_t l = 0;
    for (uint16_t i = 0,r = 0; i < buff->count;){
        // left[l] = buff->buff[i] & 0x7F;
        // left[l++] += (buff->buff[i++] & 0x80) << 24;
        //
        // right[r] = buff->buff[i] & 0x7F;
        // right[r++] += (buff->buff[i++] & 0x80) << 24;

        left[l++] += buff->buff[i++] << 24;

        right[r++] += buff->buff[i++] << 24;
    }
    count = l;
}

void AudioEffectPipelineBuffer_8::toAudioBuffer(audioBuffer* buff){
    for (uint16_t i = 0,l = 0,r = 0; i < buff->count;){
        // buff->buff[i] = left[l];
        // buff->buff[i++] += (left[l++] & 0x80000000) >> 24;
        //
        // buff->buff[i] = right[r];
        // buff->buff[i++] += (right[r++] & 0x80000000) >> 24;

        buff->buff[i++] = left[l++] >> 24;

        buff->buff[i++] = right[r++] >> 24;
    }
}
