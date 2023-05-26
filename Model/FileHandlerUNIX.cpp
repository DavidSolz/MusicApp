#include "FileHandlerUNIX.h"

char FileHandlerUNIX::openAudioWav(const std::string& fileName, audioFileInfo& info){
    audioFile.open(fileName, std::ifstream::in | std::ifstream::binary);
    if (!audioFile.is_open() || !audioFile.good()){
        return -1;
    }
    info.sampleRate = 44100;
    info.bitDepth = 16;
    info.channels = 2;
    return 0;
}

char FileHandlerUNIX::readAudio(audioBuffer* buffer){
    if (!audioFile.good()){
        return -1;
    }
    audioFile.read((char*)(buffer->buff), buffer->size);
    buffer->count = audioFile.gcount();
    return 0;
}

void FileHandlerUNIX::closeAudio(){
    if (audioFile.is_open()){
        audioFile.close();
    }
}