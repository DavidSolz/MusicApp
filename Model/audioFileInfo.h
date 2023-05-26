#ifndef _WAVINFO_H
#define _WAVINFO_H

#include <inttypes.h>

struct audioFileInfo{
    uint8_t channels;
    uint8_t bitDepth;
    uint32_t sampleRate;
    bool littleEndian;
};

#endif