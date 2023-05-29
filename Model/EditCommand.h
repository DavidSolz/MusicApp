#ifndef _EDITCOMMAND_H
#define _EDITCOMMAND_H

#include "ICommand.h"

class EditCommand : public ICommand{

void Process(const Player* player);

};

#endif