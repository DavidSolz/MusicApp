/**
 * Project Untitled
 */


#ifndef _PLAYER_H
#define _PLAYER_H

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
char AddTrack(track track, Playlist playlist);
    
/**
 * @param track
 * @param playlist
 */
char RemoveTrack(track track, Playlist playlist);
private: 
    SoundStream* soundStream;
    Playlist* queue;
    List<Playlist*> playlist;
};

#endif //_PLAYER_H