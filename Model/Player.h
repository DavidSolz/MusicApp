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
    void CreatePlaylist();
    void EditPlaylist();
    void ShowPlaylists();
    Playlist* GetQueue();
    SoundStream* GetStream();
    ~Player();

private: 
    SoundStream* soundStream;
    Playlist* queue;
    std::list<Playlist*> playlists;
};

#endif //_PLAYER_H