#include "PreviousCommand.h"

void PreviousCommand::Process(const Player *player){
    SoundStream* stream = ((Player*)player)->GetStream();

    Playlist *queue = ((Player*)player)->GetQueue();

    track *t = queue->Previous();

    if(t==NULL){
        printf("No previous songs      \n");
        return; 
    }

    if(stream->isPlaying()==true){
        stream->stop(); 
    }

   
    stream->init(t->GetPath()); //TODO
    stream->play();

}
