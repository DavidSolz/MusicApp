#include "AudioEffectPipelineBufferBuilder.h"

AudioEffectPipelineBufferBuilder::AudioEffectPipelineBufferBuilder(AudioEffectPipelineBuffer*& buffer):savedBuffer(buffer){
    savedBuffer = buffer;
    savedBuffer = nullptr;
}

AudioEffectPipelineBufferBuilder::~AudioEffectPipelineBufferBuilder(){
    if (savedBuffer){
        delete savedBuffer;
    }
}

void AudioEffectPipelineBufferBuilder::checkCompatybility(audioBuffer* buff, audioFileInfo& info){
    if (savedBuffer){
        if (buff->size != size || info.bitDepth != bitDepth){
            savedBuffer = create(buff, info);
        }
    } else {
        savedBuffer = create(buff, info);
    }
}

AudioEffectPipelineBuffer* AudioEffectPipelineBufferBuilder::create(audioBuffer* buff, audioFileInfo& info){
    uint32_t size = buff->size/(info.blockAlign/info.channels);
    AudioEffectPipelineBuffer* out;

    if (info.bitDepth == 8){
        out = new AudioEffectPipelineBuffer_8(size);
    } else if (info.bitDepth == 16){
        out = new AudioEffectPipelineBuffer_16(size);
    } else if (info.bitDepth == 24){
        out = new AudioEffectPipelineBuffer_24(size);
    } else if (info.bitDepth == 32){
        out = new AudioEffectPipelineBuffer_32(size);
    } else {
        fprintf(stderr, "ERR: unsupported bitDepth\n");
        return nullptr;
    }
    if (savedBuffer){
        delete savedBuffer;
    }
    // savedBuffer = out;

    bitDepth = info.bitDepth;
    this->size = size;

    return out;
}