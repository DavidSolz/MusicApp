#include "PauseCommand.h"

void PauseCommand::Process(const Player *player){
    SoundStream* stream = ((Player*)player)->GetStream();

    if(stream->isPlaying()==false){
        std::cerr<<"Nothing is playing\n";
        return;
    }

    stream->pause();

}
