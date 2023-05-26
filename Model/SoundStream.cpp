#include "SoundStream.h"

SoundStream::SoundStream(std::string name):name(name){
    playing = false;
    outStream = new OutStreamPulseAudio();
    fileHandler = new FileHandlerUNIX();
    buff = nullptr;
    audioThread = nullptr;
    bytesRead = 0;
}

SoundStream::~SoundStream(){
    stop();
    delete outStream;
    delete fileHandler;
    if (buff){
        delete buff;
    }
}

char SoundStream::init(const std::string& fileName){
    stop();
    if (fileHandler->openAudioWav(fileName, currentlyPlayingInfo)){
        std::cerr << "ERR: openning file" << std::endl;
        return -1;
    }

    if (buff){
        delete buff;
    }

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
    playing = false;
    if (audioThread && audioThread->joinable()){
        audioThread->join();
    }
}

void SoundStream::stop(){
    bytesRead = 0;
    pause();
    if (audioThread){
        delete audioThread;
        audioThread = nullptr;
    }
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
    if (playing){
        stop();
    }
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