
#include "Playlist.h"
#include<iostream>

void Playlist::AddTrack(const track *_track) {
    tracks.push_back((track*)_track);
}

void Playlist::RemoveTrack(const track *_track) {
    tracks.erase(std::remove(tracks.begin(), tracks.end(), _track), tracks.end());
}

void Playlist::MoveTrack(const track *_track, const int &offset) {

    auto it = std::find(tracks.begin(), tracks.end(), _track);

    if(it==tracks.end()){
        std::cerr<<"Element not found\n";
        return;
    }

    std::rotate(it,it+offset,tracks.end());


}