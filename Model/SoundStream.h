#ifndef _SOUNDSTREAM_H
#define _SOUNDSTREAM_H

#include <iostream>
#include <thread>

#include "AudioEffectPipeline.h"
#include "IFileHandler.h"
#include "IOutStream.h"

#include "OutStreamPulseAudio.h"
#include "FileHandlerUNIX.h"


class SoundStream{
public:
    SoundStream(std::string name, AudioEffectPipeline* pipeline);
    ~SoundStream();
    char init(const std::string& fileName);
    void play();
    void pause();
    void stop();

    bool isPlaying();
    void printCurrentlyPlayingInfo();
    std::string fileLength();
    std::string timeElapsed();

private:
    AudioEffectPipeline* pipeline;
    const std::string name;
    std::thread* audioThread;
    IOutStream* outStream;
    IFileHandler* fileHandler;
    bool playing;
    audioFileInfo currentlyPlayingInfo;
    unsigned long bytesRead;
    audioBuffer* buff; // if nullptr then nothing is initialized and ready to play
    void audioThreadF();
};

#endif