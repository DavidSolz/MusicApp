#include "SoundStream.h"

SoundStream::SoundStream(const uint16_t& buffSize){
    playing = false;
    outStream = new OutStreamPulseAudio();
    fileHandler = new FileHandlerUNIX();
    buff = new audioBuffer(buffSize);
}

SoundStream::~SoundStream(){
    if (playing){
        stop();
    }
    delete outStream;
    delete fileHandler;
    delete buff;
}

char SoundStream::init(const std::string& fileName){
    audioFileInfo info;

    if (fileHandler->openAudioWav(fileName, info)){
        std::cerr << "ERR: openning file" << std::endl;
        return -1;
    }

    std::cout << uint(info.bitDepth) << " " << info.sampleRate << " " << uint(info.channels) << " " << info.littleEndian << std::endl;

    if (outStream->init(info, "player.cpp", fileName)){
        std::cerr << "ERR: openning stream" << std::endl;
        return -1;
    }

    return 0;
}

void SoundStream::play(){
    if (playing == false){
        playing = true;
        audioThread = new std::thread(&SoundStream::audioThreadF, this);
    }
}

void SoundStream::pause(){
    if (playing){
        playing = false;
        audioThread->join();
    }
}

void SoundStream::stop(){
    pause();
    fileHandler->closeAudio();
}

void SoundStream::audioThreadF(){
    while (playing) {
        if (fileHandler->readAudio(buff)){
            break;
        }
        if (outStream->playBuffer(buff)){
            std::cerr << "ERR: playing" << std::endl;
            break;
        }
    }
    playing = false;
}