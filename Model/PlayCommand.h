/**
 * Project Untitled
 */


#ifndef _PLAYCOMMAND_H
#define _PLAYCOMMAND_H

#include "ICommand.h"


class PlayCommand: public ICommand {

void Process(const Player *player){
    std::cout<<"Playing\n";
}

};

#endif //_PLAYCOMMAND_H