#ifndef _IFILEHANDLER_H
#define _IFILEHANDLER_H

#include <string>
#include <fstream>

#include "audioBuffer.h"
#include "audioFileInfo.h"

class IFileHandler{
public:
    virtual char openAudioWav(const std::string& fileName, audioFileInfo& info){};
    virtual char readAudio(audioBuffer* buffer){};
    virtual void closeAudio(){};
};

#endif