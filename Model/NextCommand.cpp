#include "NextCommand.h"


void NextCommand::Process(const Player *player){
    SoundStream* stream = ((Player*)player)->GetStream();

    Playlist *queue = ((Player*)player)->GetQueue();

    track *t = queue->Next();

    if(t==NULL){
        printf("No next songs      \n");
        return; 
    }

    if(stream->isPlaying()==true){
        stream->stop(); 
    }
   
    stream->init(t->GetPath()); //TODO
    stream->play();

}
