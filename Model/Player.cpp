
#include "Player.h"

/**
 * @return char
 */
char Player::PlayNext() {
    return '0';
}

/**
 * @return char
 */
char Player::PlayPrevious() {
    return '0';
}

/**
 * @return char
 */
char Player::Play() {
    return '0';
}

/**
 * @return char
 */
char Player::Stop() {
    return '0';
}

/**
 * @param track
 * @param playlist
 * @return char
 */
char Player::AddTrack(const track &_track, Playlist &playlist) {
    try
    {
        playlist.AddTrack(_track);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

/**
 * @param track
 * @param playlist
 * @return char
 */
char Player::RemoveTrack(const track &_track, Playlist playlist) {
    try
    {
        playlist.RemoveTrack(_track);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}