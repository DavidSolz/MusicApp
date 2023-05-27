#ifndef _IFILEHANDLER_H
#define _IFILEHANDLER_H

#include <string>
#include <fstream>

#include "audioBuffer.h"
#include "audioFileInfo.h"

class IFileHandler{
public:
    virtual char openAudioWav(const std::string& fileName, audioFileInfo& info) = 0;
    virtual char readAudio(audioBuffer* buffer) = 0;
    virtual void closeAudio() = 0;
    virtual void moveTo(const uint32_t& samples) = 0;
};

#endif