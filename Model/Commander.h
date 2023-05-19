#ifndef _COMMANDER_H
#define _COMMANDER_H
#include "ICommand.h"
#include "Player.h"

class Commander {
public: 
    
Commander(const Player &player);

/**
 * @param command
 */
void SetCommand(const ICommand &command);
    
void ExecuteCommand();
private: 
    ICommand* command;
    Player* player;
};

#endif //_COMMANDER_H