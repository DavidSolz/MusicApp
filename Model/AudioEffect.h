/**
 * Project Untitled
 */


#ifndef _AUDIOEFFECT_H
#define _AUDIOEFFECT_H
#include<string>

#pragma once

class AudioEffect {
public: 
    
virtual void Compute() = 0;
    
virtual std::string GetInfo() = 0;
};

#endif //_AUDIOEFFECT_H