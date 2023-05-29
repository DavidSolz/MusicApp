
#include "Playlist.h"

Playlist::Playlist(const std::string &name){
    this->name=name;
}


bool Playlist::havePrevious(){
    return index>1 && tracks.size()>0;
}

track* Playlist::Previous(){
    if(havePrevious()){
        return tracks[--index];
        if(index<0){
            index=0;
        }
    }else{
        return NULL;
    }
}

std::string Playlist::GetPlaylistName(){
    return name;
}

std::string Playlist::GetCurrentName(){
    if(tracks.size()>0){
        return tracks[index]->GetName();
    }
    return "Queue is empty";
}

void Playlist::Add(const track* _track){
    tracks.push_back((track*)_track);
}

bool Playlist::haveNext(){
    return index < tracks.size();
}

track* Playlist::Next(){
    if(haveNext()){
        return tracks[index++];
        if(index>=tracks.size()){
            index = tracks.size()-1;
        }
    }else{
        return NULL;
    }
}

void Playlist::Reset(){
    index=0;
}