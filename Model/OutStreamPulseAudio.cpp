#include "OutStreamPulseAudio.h"

#include <iostream>
#include <pulse/sample.h>

// OutStreamPulseAudio::OutStreamPulseAudio(){
//
// }
OutStreamPulseAudio::~OutStreamPulseAudio(){
    pa_simple_drain(playbackStream, NULL);
    if (playbackStream){
        pa_simple_free(playbackStream);
    }
}
char OutStreamPulseAudio::init(const audioFileInfo& info, const std::string& appName, const std::string& description){
    sampleSpecs.channels = info.channels;
    sampleSpecs.rate = info.sampleRate;
    if (info.littleEndian){
        if (info.bitDepth == 16){
            sampleSpecs.format = PA_SAMPLE_S16LE;
        } else if (info.bitDepth == 24){
            sampleSpecs.format = PA_SAMPLE_S24LE;
        } else if (info.bitDepth == 32){
            sampleSpecs.format = PA_SAMPLE_S32LE;
        }
    } else {
        if (info.bitDepth == 16){
            sampleSpecs.format = PA_SAMPLE_S16BE;
        } else if (info.bitDepth == 24){
            sampleSpecs.format = PA_SAMPLE_S24BE;
        } else if (info.bitDepth == 32){
            sampleSpecs.format = PA_SAMPLE_S32BE;
        }
    }
    if (playbackStream){
        pa_simple_free(playbackStream);
    }
    if (!(playbackStream = pa_simple_new(NULL, appName.c_str(), PA_STREAM_PLAYBACK, NULL, description.c_str(), &sampleSpecs, NULL, NULL, NULL))) {
        return -1;
    }
    return 0;
}
char OutStreamPulseAudio::playBuffer(audioBuffer* buffer){
    if (pa_simple_write(playbackStream, buffer->buff, (size_t) buffer->count, NULL) < 0) {
        return -1;
    }
    return 0;
}
