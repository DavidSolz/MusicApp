#ifndef _IOUTSTREAM_H
#define _IOUTSTREAM_H

#include <pulse/simple.h>
#include <pulse/error.h>
#include <string>

#include "audioBuffer.h"
#include "audioFileInfo.h"

class IOutStream{
public:
    virtual char init(const audioFileInfo& info, const std::string& appName, const std::string& description) = 0;
    virtual char playBuffer(audioBuffer* buffer) = 0;
};

#endif