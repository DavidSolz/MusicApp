
#include "Player.h"


Player::Player(const std::string &streamName){
    queue = new Playlist();
    soundStream = new SoundStream(streamName);
}

Player::~Player(){
    delete queue;
    delete soundStream;
}

SoundStream * Player::GetStream(){
    return soundStream;
}

void Player::AddTrack(const track *_track, Playlist *playlist) {
    try
    {
        playlist->AddTrack((track *)_track);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void Player::RemoveTrack(const track *_track, Playlist *playlist) {
    try
    {
        playlist->RemoveTrack((track *)_track);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}