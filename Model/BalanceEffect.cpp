#include "BalanceEffect.h"

BalanceEffect::BalanceEffect(){
    balance = 0;
}

BalanceEffect::~BalanceEffect(){

}

void BalanceEffect::apply(audioBuffer* buff, const audioFileInfo& info){
    float multiplier = balance;
    uint32_t i;

    if (balance > 0){
        i = 0;
    } else if (balance < 0){
        multiplier *= -1;
        i = 1;
    } else {
        return;
    }
    multiplier = 1 - multiplier;
    uint16_t channelChunkSize = info.bitDepth/8;

    for (;i < buff->count/channelChunkSize; i+=2){
        for (uint16_t j = 0; j < channelChunkSize; j++){
            buff->buff[i*channelChunkSize+j] = char(buff->buff[i*channelChunkSize+j])*multiplier;
        }
    }
}

void BalanceEffect::set(float* settings){
    balance = *settings;
}

void BalanceEffect::getSetting(float* settings){
    *settings = balance;
}

std::string BalanceEffect::getName(){
    return "balance";
}
