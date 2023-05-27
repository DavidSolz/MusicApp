#ifndef _PREVIOUSCOMMAND_H
#define _PREVIOUSCOMMAND_H

#include "ICommand.h"

class PreviousCommand : public ICommand{

void Process(const Player *player);

};


#endif