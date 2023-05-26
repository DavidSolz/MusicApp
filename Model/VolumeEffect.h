/**
 * Project Untitled
 */


#ifndef _VOLUMEEFFECT_H
#define _VOLUMEEFFECT_H

#include "AudioEffect.h"
#include<string>

#pragma once

class VolumeEffect: public AudioEffect {
public: 
    
void Compute();
    
std::string GetInfo();
private: 
    float volume;
};

#endif //_VOLUMEEFFECT_H