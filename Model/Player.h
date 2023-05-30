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
    void Next();
    void Stop();
    void ClearQueue();
    Playlist* GetQueue();
    AudioEffectPipeline* GetPipeline();
    std::vector<Playlist*> &GetList();
    void SetList(const std::vector<Playlist*> &list);
    SoundStream* GetStream();
    ~Player();

private: 
    SoundStream* soundStream;
    AudioEffectPipeline *pipe;
    PlayerState state;
    Playlist* queue;
    std::vector<Playlist*> playlists;
};

#endif //_PLAYER_H