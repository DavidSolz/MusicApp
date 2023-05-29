
#include "Player.h"


Player::Player(const std::string &streamName, const AudioEffectPipeline * pipeline){
    soundStream = new SoundStream(streamName, (AudioEffectPipeline*)pipeline);

    playlists.push_back(new Playlist("Test1"));
    playlists.push_back(new Playlist("Test2"));
}

Player::~Player(){

    delete assembler;
    delete queue;
    delete soundStream;
}

std::vector<Playlist*> &Player::GetList(){
    return playlists;
}

SoundStream * Player::GetStream(){
    return soundStream;
}

PlaylistAssembler* Player::GetAssembler(){
    if(assembler==NULL){
        assembler = new PlaylistAssembler();
    }
    return assembler;
}

Playlist* Player::GetQueue(){
    if(queue==NULL){
        queue = new Playlist("Queue");
    }

    return queue;
}
