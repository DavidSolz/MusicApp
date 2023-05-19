
#ifndef _PLAYLIST_H
#define _PLAYLIST_H
#include "track.h"
#include<list>

#pragma once
class Playlist {
public: 

/**
 * @param track
 */
void AddTrack(const track &_track);
    
/**
 * @param track
 */
void RemoveTrack(const track &_track);
    
/**
 * @param track
 * @param offset
 */
void MoveTrack(const track &_track,const int &offset);
private: 
    std::list<track*> tracks;
    int index;
    std::string name;
};

#endif //_PLAYLIST_H