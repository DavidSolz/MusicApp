#ifndef _WAVINFO_H
#define _WAVINFO_H

#include <inttypes.h>
#include <string>
#include <cstdio>

struct audioFileInfo{
    std::string type;
    uint8_t channels;
    uint8_t bitDepth;
    uint8_t blockAlign;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint32_t fileLength;
    bool littleEndian;

    ulong length();
    ulong timeElapsed(uint32_t bytesRead);
    static std::string secondsToString(ulong seconds);
    void print();
};

#endif