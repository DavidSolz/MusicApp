
#ifndef _PLAYLIST_H
#define _PLAYLIST_H

#include<vector>
#include<string>
#include "track.h"
#include<iostream>
#pragma once

class Playlist {
public: 

Playlist(const std::string &name);

bool haveNext();

bool havePrevious();

void Add(const track* _track);

std::string GetPlaylistName();

std::vector<track*> &GetTracks();

std::string GetCurrentName();

track* Previous();

track* Next();

void Reset();

private: 
    std::vector<track*> tracks;
    int index;
    std::string name;
};

#endif //_PLAYLIST_H