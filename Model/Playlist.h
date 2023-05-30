
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
void SetPlaylistName(const std::string &name);
std::string GetPlaylistName();

std::vector<track*> &GetTracks();

void SetTracks(std::vector<track*> &list);

std::string GetCurrentName();

int GetSize();

track* GetCurrentTrack();

int GetCurrentIndex();

track* Previous();

track* Next();

void Reset();

private: 
    std::vector<track*> tracks;
    int index;
    std::string name;
};

#endif //_PLAYLIST_H