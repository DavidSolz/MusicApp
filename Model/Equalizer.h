/**
 * Project Untitled
 */


#ifndef _EQUALIZER_H
#define _EQUALIZER_H

#include "AudioEffect.h"
#include<string>

#pragma once

class Equalizer: public AudioEffect {
public: 
    
void Compute();
    
std::string GetInfo();
};

#endif //_EQUALIZER_H