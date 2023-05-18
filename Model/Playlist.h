/**
 * Project Untitled
 */


#ifndef _PLAYLIST_H
#define _PLAYLIST_H

class Playlist {
public: 
    
/**
 * @param track
 */
void AddTrack(track track);
    
/**
 * @param track
 */
void RemoveTrack(track track);
    
/**
 * @param track
 * @param offset
 */
void MoveTrack(track track, int offset);
private: 
    List<track*> tracks;
    int index;
    string name;
};

#endif //_PLAYLIST_H