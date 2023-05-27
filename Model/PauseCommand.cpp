#include "PauseCommand.h"

void PauseCommand::Process(const Player *player){
    SoundStream* stream = ((Player*)player)->GetStream();

    if(stream->isPlaying()==false)return;

    stream->pause();

}
