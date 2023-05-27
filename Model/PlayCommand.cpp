#include "PlayCommand.h"

void PlayCommand::Process(const Player *player){
    SoundStream* stream = ((Player*)player)->GetStream();

    if(stream->isPlaying()==true){
        stream->stop();
    }

    std::string filename;

    std::cin>>filename;

    stream->init(filename);
    stream->play();
    stream->printCurrentlyPlayingInfo();
}
