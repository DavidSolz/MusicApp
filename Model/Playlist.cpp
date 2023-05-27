
#include "Playlist.h"


void Playlist::Edit(){

}

bool Playlist::havePrevious(){
    return index>0;
}

track* Playlist::Previous(){
    if(havePrevious()){
        return tracks[index--];
    }else{
        return NULL;
    }
}

bool Playlist::haveNext(){
    return index < tracks.size();
}

track* Playlist::Next(){
    if(haveNext()){
        return tracks[index++];
    }else{
        return NULL;
    }
}

void Playlist::Reset(){
    index=0;
}