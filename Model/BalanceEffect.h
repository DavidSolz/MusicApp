/**
 * Project Untitled
 */


#ifndef _BALANCEEFFECT_H
#define _BALANCEEFFECT_H

#include "AudioEffect.h"


class BalanceEffect: public AudioEffect {
public: 
    
void Compute();
    
string GetInfo();
private: 
    float balance;
};

#endif //_BALANCEEFFECT_H