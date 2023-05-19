#include "Commander.h"

Commander::Commander(const Player &player){
    this->player=&(Player)player;
}

/**
 * @param ICommand command
 * @return void
 */
void Commander::SetCommand(const ICommand &command) {
    this->command = &(ICommand)command;
}

/**
 * @return void
 */
void Commander::ExecuteCommand() {
    
}