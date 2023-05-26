#ifndef _FILEHANDLERUNIX_H
#define _FILEHANDLERUNIX_H

#include "IFileHandler.h"


class FileHandlerUNIX: public IFileHandler{
public:
    char openAudioWav(const std::string& fileName, audioFileInfo& info);
    char readAudio(audioBuffer* buffer);
    void closeAudio();
private:
    std::ifstream audioFile;
};

#endif