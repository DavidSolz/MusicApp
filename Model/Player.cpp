
#include "Player.h"


Player::Player(const std::string &streamName){
    queue = new Playlist();
    soundStream = new SoundStream(streamName, new AudioEffectPipeline());
}

Player::~Player(){
    delete queue;
    delete soundStream;
}

SoundStream * Player::GetStream(){
    return soundStream;
}

Playlist* Player::GetQueue(){
    if(queue==NULL){
        queue= new Playlist();
    }

    return queue;
}

void Player::CreatePlaylist(){

}

void Player::EditPlaylist(){

}

void Player::ShowPlaylists(){

}