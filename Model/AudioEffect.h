/**
 * Project Untitled
 */


#ifndef _AUDIOEFFECT_H
#define _AUDIOEFFECT_H

class AudioEffect {
public: 
    
virtual void Compute() = 0;
    
virtual string GetInfo() = 0;
};

#endif //_AUDIOEFFECT_H