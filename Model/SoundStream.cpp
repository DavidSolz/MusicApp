#include "SoundStream.h"

SoundStream::SoundStream(std::string name, AudioEffectPipeline* pipeline):name(name), pipeline(pipeline){
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
    if (audioThread){
        delete audioThread;
    }
}

char SoundStream::init(const std::string& fileName){
    stop();
    if (fileHandler->openAudioWav(fileName, currentlyPlayingInfo)){
        fprintf(stderr , "ERR: openning file\n");
        return -1;
    }

    buff = new audioBuffer(256*currentlyPlayingInfo.blockAlign);

    if (outStream->init(currentlyPlayingInfo, name, fileName)){
        fprintf(stderr , "ERR: openning stream\n");
        return -1;
    }

    return 0;
}

void SoundStream::play(){
    if (!buff){
        fprintf(stderr, "nothing to play\n");
        return;
    }

    if (playing == false){
        playing = true;
        if (audioThread){
            delete audioThread;
        }
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
    pause();
    bytesRead = 0;
    if (buff){
        delete buff;
        buff = nullptr;
    }
    fileHandler->closeAudio();
}

void SoundStream::skipSeconds(const int& seconds){
    if (buff){
        uint32_t currnetBytesRead = bytesRead;
        long int bytesToMove = seconds * int(currentlyPlayingInfo.byteRate);
        bytesToMove -= bytesToMove % currentlyPlayingInfo.blockAlign;
        if (bytesToMove < 0){
            if (currnetBytesRead < -bytesToMove){
                currnetBytesRead = 0;
            } else {
                currnetBytesRead += bytesToMove;
            }
        } else {
            if (currnetBytesRead + bytesToMove > currentlyPlayingInfo.fileLength){
                stop();
                return;
            } else {
                currnetBytesRead += bytesToMove;
            }
        }

        bool wasPlaying = playing;
        pause();
        bytesRead = currnetBytesRead;
        fileHandler->moveTo(currnetBytesRead);
        if (wasPlaying){
            play();
        }
    }
}

void SoundStream::jumpTo(const unsigned int& minutes, unsigned int seconds){
    if (buff){
        seconds += minutes*60;
        long int bytesToMove = seconds * int(currentlyPlayingInfo.byteRate);
        bytesToMove -= bytesToMove % currentlyPlayingInfo.blockAlign;
        if (bytesToMove > currentlyPlayingInfo.fileLength){
            stop();
            return;
        }
        bytesRead = bytesToMove;
        bool wasPlaying = playing;
        pause();
        fileHandler->moveTo(bytesToMove);
        if (wasPlaying){
            play();
        }
    }
}

void SoundStream::audioThreadF(){
    while (playing) {
        if (fileHandler->readAudio(buff)){
            break;
        }
        bytesRead += buff->count;

        pipeline->apply(buff, currentlyPlayingInfo);

        if (outStream->playBuffer(buff)){
            fprintf(stderr ,"ERR: playing\n");
            break;
        }
    }
    if (playing){
        playing = false;
        bytesRead = 0;
        if (buff){
            delete buff;
            buff = nullptr;
        }
        fileHandler->closeAudio();
    }
}

bool SoundStream::isPlaying(){
    return playing;
}

void SoundStream::printCurrentlyPlayingInfo(){
    if (buff){
        currentlyPlayingInfo.print();
    } else {
        fprintf(stderr, "nothing to show\n");
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