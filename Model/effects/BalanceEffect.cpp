#include "BalanceEffect.h"

BalanceEffect::BalanceEffect(){
    balance = 0;
}

BalanceEffect::~BalanceEffect(){

}

void BalanceEffect::apply(AudioEffectPipelineBuffer* buff, const audioFileInfo& info){
    float multiplier = balance;


    if (balance > 0){
        multiplier = 1 - multiplier;
        for (uint16_t i = 0; i < buff->getCount(); i++){
            buff->right[i] *= multiplier;
        }
    } else if (balance < 0){
        multiplier = 1 - multiplier*-1;
        for (uint16_t i = 0; i < buff->getCount(); i++){
            buff->left[i] *= multiplier;
        }
    } else {
        return;
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
