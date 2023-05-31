#include "audioFileInfo.h"
#include <string>

unsigned long audioFileInfo::length(){
    return fileLength/byteRate;
}

unsigned long audioFileInfo::timeElapsed(uint32_t bytesRead){
    return bytesRead/byteRate;
}

std::string audioFileInfo::secondsToString(unsigned long seconds){
    unsigned int minutes = seconds/60;
    seconds = seconds%60;
    std::string out = "";
    if (minutes < 10){
        out += "0";
    }
    out += std::to_string(minutes);
    out += ':';
    if (seconds < 10){
        out += "0";
    }
    if (seconds == 0){
        out += "0";
    } else {
        out += std::to_string(seconds);
    }
    return out;
}

void audioFileInfo::print(){
    printf("type: %s\n", type.c_str());
    printf("channels: %d\nbitDepth: %d\nblockAlign: %d\nsampleRate: %d\nbyteRate: %d\nfileLength: %d\n", channels, bitDepth, blockAlign, sampleRate, byteRate, fileLength);
    if (littleEndian){
        printf("littleEndian\n");
    } else {
        printf("bigEndian\n");
    }
}