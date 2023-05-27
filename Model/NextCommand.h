#ifndef _NEXTCOMMNAD_H
#define _NEXTCOMMAND_H
#include "ICommand.h"

class NextCommand : public ICommand{

void Process(const Player *player);

};


#endif