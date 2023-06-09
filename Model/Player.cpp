
#include "Player.h"


Player::Player(const std::string &streamName, const AudioEffectPipeline * pipeline){
    pipe = (AudioEffectPipeline*)pipeline;
    soundStream = new SoundStream(streamName, pipe);
    queue = new Playlist("Queue");

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
    track *t = queue->Next();
    if(t==NULL){
        queue->Reset();
    }
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

void Player::Skip(const int &seconds){
    if(soundStream->isPlaying()==false){
        return;
    }

    soundStream->skipSeconds(seconds);

}

Player::~Player(){
    if(loopThread!=NULL){
        loopThread->join();
        delete loopThread;
    }
    delete queue;
    delete soundStream;
}

bool Player::isLooping(){
    return loopThread!=NULL;
}

void Player::LoopMode(){
    if(loopThread==NULL){
        loopThread==new std::thread([this](){



        });
    }else{
        loopThread->join();
        delete loopThread;
    }
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

AudioEffectPipeline* Player::GetPipeline(){
    return pipe;
}

Playlist* Player::GetQueue(){

    return queue;
}
