
#include "Playlist.h"

Playlist::Playlist(const std::string &name){
    this->name=name;
    index=0;
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

std::vector<track*> &Playlist::GetTracks(){
    return tracks;
}

int Playlist::GetSize(){
    return tracks.size();
}

void Playlist::SetTracks(std::vector<track*> &list){
    this->tracks=list;
}

void Playlist::SetPlaylistName(const std::string &name){
    this->name=name;
}

std::string Playlist::GetPlaylistName(){
    return name;
}

track* Playlist::GetCurrentTrack(){
    if(index<tracks.size()){
        return tracks[index];
    }else{
        index=0;
        return NULL;
    } 
}

int Playlist::GetCurrentIndex(){
    return this->index;
}

std::string Playlist::GetCurrentName(){
    if(tracks.size()>0){
        return tracks[index-1]->GetName();
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
        int temp = index;

        if(temp+1>=tracks.size()){
            index=0;
        }

        return tracks[temp];

    }else{
        return NULL;
    }
}

void Playlist::Reset(){
    index=0;
}