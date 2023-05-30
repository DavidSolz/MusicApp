
#include "Player.h"


Player::Player(const std::string &streamName, const AudioEffectPipeline * pipeline){
    soundStream = new SoundStream(streamName, (AudioEffectPipeline*)pipeline);
    queue = new Playlist("Queue");

    queue->Add(new track("First", "/Users/solz/Desktop/MusicApp/Out/Firstborn.wav"));

    state = IDLE;
}


void Player::Play(){

    if(queue->GetSize()==0)return;

    if(soundStream->isPlaying()==true){
        state=STOP;
        soundStream->stop();
    }

    track *t=queue->GetCurrentTrack();

    if(t==NULL){
       return;
    }

    if(state!=PAUSE)soundStream->init(t->GetPath());
    state=PLAY;
    soundStream->play();
}

void Player::Next(){
    if(queue->GetSize()==0)return;
    queue->Next();
}

void Player::Pause(){
    if(soundStream->isPlaying()==false){
        return;
    }

    state=PAUSE;
    soundStream->pause();
}
void Player::Stop(){
    if(soundStream->isPlaying()==false){
        return;
    }
    state=STOP;
    soundStream->stop();
}


Player::~Player(){
    delete queue;
    delete soundStream;
}

std::vector<Playlist*> &Player::GetList(){
    return playlists;
}

void Player::ClearQueue(){
    queue->GetTracks().clear();
}

void Player::SetList(const std::vector<Playlist*> &list){
    this->playlists=list;
}

SoundStream * Player::GetStream(){
    return soundStream;
}

Playlist* Player::GetQueue(){

    return queue;
}
