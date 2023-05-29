
#include "Player.h"


Player::Player(const std::string &streamName, const AudioEffectPipeline * pipeline){
    queue = new Playlist();
    soundStream = new SoundStream(streamName, (AudioEffectPipeline*)pipeline);
}

Player::~Player(){

    delete assembler;
    delete queue;
    delete soundStream;
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
        queue = new Playlist();
    }

    return queue;
}

void Player::CreatePlaylist(){

}

void Player::EditPlaylist(){

}

void Player::ShowPlaylists(){

}