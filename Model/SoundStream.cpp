#include "SoundStream.h"

SoundStream::SoundStream(std::string name):name(name){
    playing = false;
    outStream = new OutStreamPulseAudio();
    fileHandler = new FileHandlerUNIX();
    buff = nullptr;
}

SoundStream::~SoundStream(){
    if (playing){
        stop();
    }
    delete outStream;
    delete fileHandler;
    if (buff){
        delete buff;
    }
}

char SoundStream::init(const std::string& fileName){
    if (fileHandler->openAudioWav(fileName, currentlyPlayingInfo)){
        std::cerr << "ERR: openning file" << std::endl;
        return -1;
    }

    if (buff){
        delete buff;
    }
    bytesRead = 0;
    buff = new audioBuffer(512*currentlyPlayingInfo.blockAlign);

    if (outStream->init(currentlyPlayingInfo, name, fileName)){
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
        bytesRead += buff->count;
        if (outStream->playBuffer(buff)){
            std::cerr << "ERR: playing" << std::endl;
            break;
        }
    }
    playing = false;
}

bool SoundStream::isPlaying(){
    return playing;
}

void SoundStream::printCurrentlyPlayingInfo(){
    currentlyPlayingInfo.print();
}
std::string SoundStream::fileLength(){
    return audioFileInfo::secondsToString(currentlyPlayingInfo.length());
}
std::string SoundStream::timeElapsed(){
    return audioFileInfo::secondsToString(currentlyPlayingInfo.timeElapsed(bytesRead));
}