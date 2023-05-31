#include "AudioEffectPipelineBuffer_8.h"
#include "AudioEffectPipelineBuffer_16.h"
#include "AudioEffectPipelineBuffer_24.h"
#include "AudioEffectPipelineBuffer_32.h"

#include "audioFileInfo.h"


class AudioEffectPipelineBufferBuilder{
public:
    AudioEffectPipelineBufferBuilder(AudioEffectPipelineBuffer*& buffer);
    ~AudioEffectPipelineBufferBuilder();

    void checkCompatybility(audioBuffer* buff, audioFileInfo& info);

private:
    AudioEffectPipelineBuffer* create(audioBuffer* buff, audioFileInfo& info);
    AudioEffectPipelineBuffer*& savedBuffer;
    uint8_t bitDepth;
    uint16_t size;
};