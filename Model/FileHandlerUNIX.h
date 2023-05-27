#ifndef _FILEHANDLERUNIX_H
#define _FILEHANDLERUNIX_H

#include "IFileHandler.h"


class FileHandlerUNIX: public IFileHandler{
public:
    char openAudioWav(const std::string& fileName, audioFileInfo& info);
    char readAudio(audioBuffer* buffer);
    void closeAudio();
    void moveTo(const uint32_t& samples);
private:
    std::fstream audioFile;
    std::streampos audioDataSegment;
};

#endif