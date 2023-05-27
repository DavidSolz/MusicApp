
#ifndef _PLAYLIST_H
#define _PLAYLIST_H

#include<vector>
#include<string>
#include "track.h"
#include<iostream>
#pragma once

class Playlist {
public: 

void Edit();

bool haveNext();

bool havePrevious();

track* Previous();

track* Next();

void Reset();

private: 
    std::vector<track*> tracks;
    int index;
    std::string name;
};

#endif //_PLAYLIST_H