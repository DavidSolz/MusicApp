#include "StopCommand.h"

void StopCommand::Process(const Player *player){
    SoundStream *stream = ((Player *)player)->GetStream();
    if(stream->isPlaying()==false){
        std::cout<<"Nothing is playing\n";
        return;
    }
    stream->stop();
}