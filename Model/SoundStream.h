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

    void skipSeconds(const int& seconds);
    void jumpTo(const unsigned int& minutes, unsigned int seconds);

private:
    const std::string name;
    AudioEffectPipeline* pipeline;
    IOutStream* outStream;
    IFileHandler* fileHandler;
    std::thread* audioThread;
    bool playing;
    audioFileInfo currentlyPlayingInfo;
    audioBuffer* buff; // if nullptr then nothing is initialized and ready to play
    uint32_t bytesRead;

    void audioThreadF();
};

#endif