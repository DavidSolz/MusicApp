
#ifndef _PLAYLIST_H
#define _PLAYLIST_H

#include<vector>
#include<string>
#include "track.h"

#pragma once
class Playlist {
public: 

/**
 * @param track
 */
void AddTrack(const track *_track);
    
/**
 * @param track
 */
void RemoveTrack(const track *_track);

/**
 * @param track
 * @param offset
 */
void MoveTrack(const track *_track,const int &offset);
private: 
    std::vector<track*> tracks;
    int index;
    std::string name;
};

#endif //_PLAYLIST_H