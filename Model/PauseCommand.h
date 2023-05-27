#ifndef _PAUSECOMMAND_H
#define _PAUSECOMMAND_H

#include "ICommand.h"

class PauseCommand: public ICommand {

void Process(const Player *player);

};

#endif //_PAUSECOMMAND_H