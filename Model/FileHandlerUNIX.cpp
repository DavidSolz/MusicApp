#include "FileHandlerUNIX.h"
#include <iostream>
#include <ostream>

uint64_t convert(const uint8_t data[], uint bytes){
    uint64_t out = 0;
    uint64_t multiplier = 1;
    for (uint i = 0; i < bytes; i++){
        out += data[i] * multiplier;
        multiplier *= 256;
    }
    return out;
}

char FileHandlerUNIX::openAudioWav(const std::string& fileName, audioFileInfo& info){
    audioFile.open(fileName, std::ifstream::in | std::ifstream::binary);
    if (!audioFile.is_open() || !audioFile.good()){
        return -1;
    }

    uint8_t riffIndicator[5], chunkSize[4], dump[4], subchunk1Size[4], audioFormat[2], numChannels[2], sampleRate[4], byteRate[4], blockAlign[2], bitsPerSample[2], subchunk2Size[4];
    riffIndicator[4] = 0;
    audioFile.read((char*)riffIndicator, 4);
    audioFile.read((char*)chunkSize, 4);
    audioFile.read((char*)dump, 4);
    audioFile.read((char*)dump, 4);
    audioFile.read((char*)subchunk1Size, 4);
    audioFile.read((char*)audioFormat, 2);
    audioFile.read((char*)numChannels, 2);
    audioFile.read((char*)sampleRate, 4);
    audioFile.read((char*)byteRate, 4);
    audioFile.read((char*)blockAlign, 2);
    audioFile.read((char*)bitsPerSample, 2);

    while (true){
        audioFile.read((char*)dump, 1);
        if (dump[0] == 'd'){
            audioFile.read((char*)dump+1, 3);
            if (dump[1] == 'a' && dump[2] == 't' && dump[3] == 'a'){
                break;
            }
        }
    }

    audioFile.read((char*)subchunk2Size, 4);
    audioDataSegment = audioFile.tellp();

    info.type = "wave";
    info.sampleRate = convert(sampleRate, 4);
    info.bitDepth = convert(bitsPerSample, 2);
    info.channels = convert(numChannels, 2);
    info.blockAlign = convert(blockAlign, 2);
    info.fileLength = convert(subchunk2Size, 4);
    info.byteRate = convert(byteRate, 4);
    if (riffIndicator[3] == 'F'){
        info.littleEndian = true;
    } else if (riffIndicator[3] == 'X'){
        info.littleEndian = false;
    }
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

void FileHandlerUNIX::moveTo(const uint32_t& samples){
    audioFile.seekp(audioDataSegment, std::ios_base::beg);
    audioFile.seekp(samples, std::ios_base::cur);
}