/**
 * Project Untitled
 */


#ifndef _COMMANDER_H
#define _COMMANDER_H

class Commander {
public: 
    
/**
 * @param ICommand command
 */
void SetCommand(void ICommand command);
    
void ExecuteCommand();
private: 
    ICommand* command;
    Player* player;
};

#endif //_COMMANDER_H