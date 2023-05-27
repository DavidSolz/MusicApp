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
}

char SoundStream::init(const std::string& fileName){
    stop();
    if (fileHandler->openAudioWav(fileName, currentlyPlayingInfo)){
        fprintf(stderr , "ERR: openning file\n");
        return -1;
    }

    buff = new audioBuffer(512*currentlyPlayingInfo.blockAlign);

    if (outStream->init(currentlyPlayingInfo, name, fileName)){
        fprintf(stderr , "ERR: openning stream\n");
        return -1;
    }

    return 0;
}

void SoundStream::play(){
    if (!buff){
        printf("nothing to play\n");
        return;
    }

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
    if (buff){
        delete buff;
        buff = nullptr;
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
            fprintf(stderr ,"ERR: playing\n");
            break;
        }
    }
    if (playing){
        fileHandler->closeAudio();
        playing = false;
    }

}

bool SoundStream::isPlaying(){
    return playing;
}

void SoundStream::printCurrentlyPlayingInfo(){
    if (buff){
        currentlyPlayingInfo.print();
    } else {
        printf("nothing to show\n");
    }
}
std::string SoundStream::fileLength(){
    if (buff){
        return audioFileInfo::secondsToString(currentlyPlayingInfo.length());
    } else {
        return "00:00";
    }
}
std::string SoundStream::timeElapsed(){
    if (buff){
        return audioFileInfo::secondsToString(currentlyPlayingInfo.timeElapsed(bytesRead));
    } else {
        return "00:00";
    }
}