#include "Commander.h"

Commander::Commander(const Player *player){
    this->player=(Player*)player;
    this->command=NULL;
}

void Commander::AddCommand(const std::string &commandName, const ICommand *command){
    bool exists = (commands.count(commandName) > 0);

    if(exists==true){
        std::cerr<<"Command is already registered\n";
        return;
    }

    commands[commandName] = (ICommand*)command;

}

bool Commander::SetCommand(const std::string &command) {
    try
    {
        ICommand *tempC = commands.at(command); 


        this->command = tempC;
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Unknown command\n";;
    }

    return false;
}

void Commander::DumpToFile(const std::string &filename){
    //TODO
}

void Commander::ReadFromFile(const std::string &filename){
    //TODO
}

void Commander::ExecuteCommand() {

    if(command==NULL){
        std::cerr << "Command not set\n";
        return;
    }

    command->Process(player);

}

void Commander::ExecuteCommand(const std::string &command) {

    if(SetCommand(command)==false){ 
        return;
    }
    ExecuteCommand();
}

void Commander::ExecuteCommand(const ICommand *command) {

    this->command=(ICommand*)command;
    ExecuteCommand();

}