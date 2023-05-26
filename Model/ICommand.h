#ifndef _ICOMMAND_H
#define _ICOMMAND_H
#include "Player.h"

class ICommand {
public:

virtual void Process(const Player *player) = 0;


};

#endif