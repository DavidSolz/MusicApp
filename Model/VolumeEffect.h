/**
 * Project Untitled
 */


#ifndef _VOLUMEEFFECT_H
#define _VOLUMEEFFECT_H

#include "AudioEffect.h"


class VolumeEffect: public AudioEffect {
public: 
    
void Compute();
    
string GetInfo();
private: 
    float volume;
};

#endif //_VOLUMEEFFECT_H