#ifndef _HELPCOMMAND_H
#define _HELPCOMMAND_H

#include "ICommand.h"

class HelpCommand : public ICommand{

void Process(const Player* player);

};

#endif


