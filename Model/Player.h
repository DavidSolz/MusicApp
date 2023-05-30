#ifndef _PLAYER_H
#define _PLAYER_H
#include "SoundStream.h"
#include "PlaylistAssembler.h"
#include<iostream>
#include<vector>

#pragma once
class Player {
public: 

    enum PlayerState{
        IDLE,
        PLAY,
        STOP,
        PAUSE
    };


    Player(const std::string &streamName, const AudioEffectPipeline * pipeline);
    void Play();
    void Pause();
    void Stop();
    Playlist* GetQueue();
    std::vector<Playlist*> &GetList();
    PlaylistAssembler* GetAssembler();
    SoundStream* GetStream();
    ~Player();

private: 
    PlaylistAssembler *assembler;
    SoundStream* soundStream;
    PlayerState state;
    Playlist* queue;
    std::vector<Playlist*> playlists;
};

#endif //_PLAYER_H