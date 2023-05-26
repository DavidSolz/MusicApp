#ifndef _COMMANDER_H
#define _COMMANDER_H
#include "ICommand.h"
#include "Player.h"
#include<map>

#pragma once


class Commander {
public: 
    
Commander(const Player *player);

/**
 * @param commandName
 * @param command
*/
void AddCommand(const std::string &commandName, const ICommand *command);

/**
 * @param command
 */
void SetCommand(const ICommand *command);

/**
 * @param command
 */
void SetCommand(const std::string &command);

/**
 * @param filename  
*/
void DumpToFile(const std::string &filename);

/**
 * @param filename  
*/
void ReadFromFile(const std::string &filename);


void ExecuteCommand();

private: 
    ICommand *command;
    Player *player;
    std::map<std::string, ICommand*> commands;
};

#endif //_COMMANDER_H