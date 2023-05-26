/**
 * Project Untitled
 */


#ifndef _BALANCEEFFECT_H
#define _BALANCEEFFECT_H

#include "AudioEffect.h"
#include<string>
#pragma once

class BalanceEffect: public AudioEffect {
public: 
    
void Compute();
    
std::string GetInfo();
private: 
    float balance;
};

#endif //_BALANCEEFFECT_H