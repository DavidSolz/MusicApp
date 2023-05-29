#include "PlayCommand.h"

void PlayCommand::Process(const Player *player){
    SoundStream* stream = ((Player*)player)->GetStream();

    if(stream->isPlaying()==true){
        stream->stop();
    }

    Playlist *queue = ((Player*)player)->GetQueue();

    if(!queue->haveNext()){
        queue->Reset();
    }

    track *t = queue->Next();

    if( t==NULL){
       printf("Queue is empty      \n");
       return; 
    }

    stream->init(t->GetPath()); //TODO
    stream->play();

}
