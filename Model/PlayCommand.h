#ifndef _PLAYCOMMAND_H
#define _PLAYCOMMAND_H

#include "ICommand.h"


class PlayCommand: public ICommand {

void Process(const Player *player);

};

#endif //_PLAYCOMMAND_H