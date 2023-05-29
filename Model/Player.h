#ifndef _PLAYER_H
#define _PLAYER_H
#include "SoundStream.h"
#include "PlaylistAssembler.h"
#include<iostream>
#include<vector>

#pragma once
class Player {
public: 


    Player(const std::string &streamName, const AudioEffectPipeline * pipeline);
    Playlist* GetQueue();
    std::vector<Playlist*> &GetList();
    PlaylistAssembler* GetAssembler();
    SoundStream* GetStream();
    ~Player();

private: 
    PlaylistAssembler *assembler;
    SoundStream* soundStream;
    Playlist* queue;
    std::vector<Playlist*> playlists;
};

#endif //_PLAYER_H