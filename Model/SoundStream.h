#ifndef _SOUNDSTREAM_H
#define _SOUNDSTREAM_H

#include <iostream>
#include <thread>

#include "IFileHandler.h"
#include "IOutStream.h"

#include "OutStreamPulseAudio.h"
#include "FileHandlerUNIX.h"


class SoundStream{
public:
    SoundStream(const uint16_t& buffSize);
    ~SoundStream();
    char init(const std::string& fileName);
    void play();
    void pause();
    void stop();

private:
    std::thread* audioThread;
    IOutStream* outStream;
    IFileHandler* fileHandler;
    bool playing;

    audioBuffer* buff;
    void audioThreadF();
};

#endif