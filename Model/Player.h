#ifndef _PLAYER_H
#define _PLAYER_H
#include "SoundStream.h"
#include "PlaylistAssembler.h"
#include<iostream>
#include<list>

#pragma once
class Player {
public: 
    Player(const std::string &streamName);
    void Play();
    void Stop();
    void PlayNext();
    void PlayPrevious();
    SoundStream *GetStream();
    ~Player();

    void AddTrack(const track *_track, Playlist *playlist);  
    void RemoveTrack(const track *_track, Playlist *playlist);

private: 
    SoundStream* soundStream;
    Playlist* queue;
    std::list<Playlist*> playlists;
};

#endif //_PLAYER_H