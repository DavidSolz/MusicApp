#ifndef _AUDIOEFFECTPIPELINEBUFFER_H
#define _AUDIOEFFECTPIPELINEBUFFER_H

#include "audioBuffer.h"
#include "audioFileInfo.h"
#include <cstdint>

template<typename SAMPLE>
struct audioEffectPipelineBuffer{
    SAMPLE* left;
    SAMPLE* right;

    uint16_t count;
    const uint16_t size;
    const uint8_t bytesPerSample;

    const SAMPLE inputSignMask;//WILL NOT WORK
    const SAMPLE SAMPLE_signMask;

    static void* creator(audioBuffer* buff, audioFileInfo& info){
        uint32_t size = buff->size/(info.blockAlign/info.channels);
        audioEffectPipelineBuffer* out;

        if (info.bitDepth <= 8){
            out = new audioEffectPipelineBuffer<int8_t>(size, info.bitDepth, info.blockAlign/info.channels);
        } else if (info.bitDepth <= 16){
            out = new audioEffectPipelineBuffer<int16_t>(size, info.bitDepth, info.blockAlign/info.channels);
        } else if (info.bitDepth <= 32){
            out = new audioEffectPipelineBuffer<int32_t>(size, info.bitDepth, info.blockAlign/info.channels);
        } else {
            out = new audioEffectPipelineBuffer<int64_t>(size, info.bitDepth, info.blockAlign/info.channels);
        }

        return out;
    }

    ~audioEffectPipelineBuffer(){
        delete[] left;
        delete[] right;
    }

    void fromAudioBuffer(audioBuffer* buff);
    void toAudioBuffer(audioBuffer* buff);

private:
    audioEffectPipelineBuffer(uint32_t size, uint8_t bitDepth, uint8_t bytesPerSample):
    size(size), bytesPerSample(bytesPerSample), inputSignMask(1 << (bitDepth-1)), SAMPLE_signMask(1 << (sizeof(SAMPLE)*8-1)){
        left = new SAMPLE[size];
        right = new SAMPLE[size];
    }
};

template<>
inline void audioEffectPipelineBuffer<int8_t>::fromAudioBuffer(audioBuffer* buff){
    for (uint16_t i = 0,l = 0,r = 0; i < buff->count;){
        left[l++] = buff->buff[i++];
        right[r++] = buff->buff[i++];
    }
}
template<>
inline void audioEffectPipelineBuffer<int8_t>::toAudioBuffer(audioBuffer* buff){
    for (uint16_t i = 0,l = 0,r = 0; i < buff->count;){
        buff->buff[i++] = left[l++];
        buff->buff[i++] = right[r++];
    }
}

template<>
inline void audioEffectPipelineBuffer<int16_t>::fromAudioBuffer(audioBuffer* buff){
    // for (uint16_t i = 0,l = 0,r = 0; i < buff->count;){
    //     left[l] = buff->buff[i++];
    //     if (buff->buff[i] & inputSignMask){
    //         left[l] += (buff->buff[i++] & ~inputSignMask) << 8;
    //         left[l++] += SAMPLE_signMask;
    //     } else {
    //         left[l++] += buff->buff[i++] << 8;
    //     }
    //     right[r] = buff->buff[i++];
    //     if (buff->buff[i] & inputSignMask){
    //         right[r] += (buff->buff[i++] & ~inputSignMask) << 8;
    //         right[r++] += SAMPLE_signMask;
    //     } else {
    //         right[r++] += buff->buff[i++] << 8;
    //     }
    // }
    for (uint16_t i = 0,l = 0,r = 0; i < buff->count;){
        left[l] = buff->buff[i++];
        left[l++] += buff->buff[i++] << 8;
        right[r] = buff->buff[i++];
        right[r++] += buff->buff[i++] << 8;
    }
}
template<>
inline void audioEffectPipelineBuffer<int16_t>::toAudioBuffer(audioBuffer* buff){
    for (uint16_t i = 0,l = 0,r = 0; i < buff->count;){
        buff->buff[i++] = left[l];
        buff->buff[i++] = left[l++] >> 8;
        buff->buff[i++] = right[r];
        buff->buff[i++] = right[r++] >> 8;
    }
}
template<>
inline void audioEffectPipelineBuffer<int32_t>::fromAudioBuffer(audioBuffer* buff){

}
template<>
inline void audioEffectPipelineBuffer<int32_t>::toAudioBuffer(audioBuffer* buff){

}
template<>
inline void audioEffectPipelineBuffer<int64_t>::fromAudioBuffer(audioBuffer* buff){

}
template<>
inline void audioEffectPipelineBuffer<int64_t>::toAudioBuffer(audioBuffer* buff){

}

#endif