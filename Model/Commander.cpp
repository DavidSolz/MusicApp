#include "Commander.h"
#include "ICommand.h"

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

    commands[commandName] = (ICommand*)&command;

}

void Commander::SetCommand(const std::string &command) {
    try
    {
        ICommand *temp = commands.at(command);
        if(temp==NULL){
            std::cerr<<"Unknown command.\n";
            return;
        }
        this->command = temp;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Commander::DumpToFile(const std::string &filename){
    //TODO
}

void Commander::ReadFromFile(const std::string &filename){
    //TODO
}


void Commander::SetCommand(const ICommand *command) {
    this->command = (ICommand*)command;
}

void Commander::ExecuteCommand() {

    if(command==NULL){
        std::cerr << "Command not set\n";
        return;
    }

    command->Process(player);

}