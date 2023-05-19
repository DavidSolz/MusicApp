
#include "Playlist.h"

/**
 * @param track
 */
void Playlist::AddTrack(const track &_track) {
    tracks.push_back(&(track)_track);
}

/**
 * @param track
 */
void Playlist::RemoveTrack(const track &_track) {
    tracks.remove(&(track)_track);
}

/**
 * @param track
 * @param offset
 */
// TODO
void Playlist::MoveTrack(const track &_track, const int &offset) {
    
    std::list<track*>::iterator it;

    /*
        Algorithm:
        1) Find position of track
        2) Remove track from that position
        3) Add offset to position
        4) Insert track ad offseted position
    */

    RemoveTrack(_track);



}