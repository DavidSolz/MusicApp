#ifndef _COMMANDER_H
#define _COMMANDER_H
#include "ICommand.h"
#include "Player.h"
#include<map>

#pragma once


class Commander {
public: 
    
Commander(const Player *player);

void AddCommand(const std::string &commandName, const ICommand *command);

/**
 * @param filename  
*/
void DumpToFile(const std::string &filename);

/**
 * @param filename  
*/
void ReadFromFile(const std::string &filename);

void ExecuteCommand();

void ExecuteCommand(const std::string &command);

void ExecuteCommand(const ICommand *command);

private: 

/**
 * @param command
 */
bool SetCommand(const std::string &command);

    ICommand *command;
    Player *player;
    std::map<std::string, ICommand*> commands;
};

#endif //_COMMANDER_H