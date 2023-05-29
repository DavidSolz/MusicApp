
#include "Player.h"


Player::Player(const std::string &streamName, const AudioEffectPipeline * pipeline){
    soundStream = new SoundStream(streamName, (AudioEffectPipeline*)pipeline);
    queue = new Playlist("Queue");

    Playlist *p = new Playlist("Test1");
    p->Add(new track("Sample.wav", "/Users/solz/Desktop/MusicApp/Out/Sample.wav"));

    playlists.push_back(p);
    playlists.push_back(new Playlist("Test2"));
}

void Player::Play(){
    if(soundStream->isPlaying()==true){
        soundStream->stop();
    }
    
    if(!queue->haveNext()){
        queue->Reset();
    }

    track *t = queue->Next();

    if( t==NULL){
       return; 
    }

    soundStream->init(t->GetPath()); //TODO
    soundStream->play();
}
void Player::Pause(){
    if(soundStream->isPlaying()==false){
        return;
    }

    soundStream->pause();
}
void Player::Stop(){
    if(soundStream->isPlaying()==false){
        return;
    }
    soundStream->stop();
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

    return queue;
}
