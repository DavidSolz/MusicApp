#include "NextCommand.h"


void NextCommand::Process(const Player *player){
    SoundStream *stream = ((Player*)player)->GetStream();
    if(stream->isPlaying()==false){
        std::cout<<"Nothing is playing\n";
        return;
    }
    stream->stop();

    Playlist * queue = ((Player*)player)->GetQueue();


    if(!queue->haveNext()){
        queue->Reset();
    }

    track* t = queue->Next();

    if( t==NULL){
       std::cerr<<"Queue is empty\n";
       return; 
    }

    stream->init(t->GetPath()); //TODO
    stream->play();
    

}
