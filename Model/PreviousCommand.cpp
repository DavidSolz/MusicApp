#include "PreviousCommand.h"

void PreviousCommand::Process(const Player *player){
    SoundStream* stream = ((Player*)player)->GetStream();

    if(stream->isPlaying()==true){
        stream->stop();
    }

    Playlist *queue = ((Player*)player)->GetQueue();

    track *t = queue->Previous();

    if( t==NULL){
       std::cerr<<"Queue is empty\n";
       return; 
    }

    stream->init(t->GetPath()); //TODO
    stream->play();

}
