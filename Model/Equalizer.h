/**
 * Project Untitled
 */


#ifndef _EQUALIZER_H
#define _EQUALIZER_H

#include "AudioEffect.h"


class Equalizer: public AudioEffect {
public: 
    
void Compute();
    
string GetInfo();
};

#endif //_EQUALIZER_H