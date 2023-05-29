#ifndef _PLAYER_H
#define _PLAYER_H
#include "SoundStream.h"
#include "PlaylistAssembler.h"
#include<iostream>
#include<list>

#pragma once
class Player {
public: 


    Player(const std::string &streamName, const AudioEffectPipeline * pipeline);
    void CreatePlaylist();
    void EditPlaylist();
    void ShowPlaylists();
    Playlist* GetQueue();
    PlaylistAssembler* GetAssembler();
    SoundStream* GetStream();
    ~Player();

private: 
    PlaylistAssembler *assembler;
    SoundStream* soundStream;
    Playlist* queue;
    std::list<Playlist*> playlists;
};

#endif //_PLAYER_H