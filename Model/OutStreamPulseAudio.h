#ifndef _OUTSTREAMPULSEAUDIO_H
#define _OUTSTREAMPULSEAUDIO_H

#include "IOutStream.h"

class OutStreamPulseAudio : public IOutStream{
public:
    // OutStreamPulseAudio();
    ~OutStreamPulseAudio();
    char init(const audioFileInfo& info, const std::string& appName, const std::string& description);
    char playBuffer(audioBuffer* buffer);
private:
    pa_simple *playbackStream;
    pa_sample_spec sampleSpecs;
};

#endif