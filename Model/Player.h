#ifndef _PLAYER_H
#define _PLAYER_H
//#include "SoundStream.h"
#include "Playlist.h"
#include<iostream>

#pragma once
class Player {
public: 
    
char PlayNext();
    
char PlayPrevious();
    
char Play();
    
char Stop();
    
/**
 * @param track
 * @param playlist
 */
char AddTrack(const track *_track, Playlist *playlist);
    
/**
 * @param track
 * @param playlist
 */
char RemoveTrack(const track *_track, Playlist *playlist);
private: 
    //SoundStream* soundStream;
    Playlist* queue;
    //std::list<Playlist*> playlist;
};

#endif //_PLAYER_H