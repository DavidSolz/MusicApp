#ifndef _STOPCOMMAND_H
#define _STOPCOMMAND_H

#include "ICommand.h"


class StopCommand: public ICommand {

void Process(const Player *player);

};

#endif //_STOPCOMMAND_H