
#include "Commander.h"
#include "PlayCommand.h"
#include "PauseCommand.h"
#include "StopCommand.h"
#include "NextCommand.h"
#include "PreviousCommand.h"

void HandleCommands(const Commander *commander);

void RegisterCommands(Commander *commander);

int main(int argc, char* argv[]){

    Player *player = new Player(argv[0]);

    Commander *commander = new Commander(player);

    RegisterCommands(commander);

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    std::thread *commandHandler = new std::thread(HandleCommands,commander);

    //TODO
    std::cout<<"Player loop\n";
    //

    commandHandler->join();

    std::cout << "\033[" << 24 << ";1H\033[K"; //Clears line
    std::cout<<"Have a nice day !\n";

    delete commander;
    delete player;

    return 0;
}

void HandleCommands(const Commander *commander){
    std::string command;
    while(true){
        std::cout << "\033[" << 23 << ";" << 0 << "H"; //Sets cursor position
        std::cout << "\033[" << 23 << ";1H\033[K"; //Clears line
        std::cout<<"> ";
        std::cin>>command;
        if(command=="Exit" || command=="exit"){
            break;
        }
        ((Commander*)commander)->ExecuteCommand(command);
    }
}

void RegisterCommands(Commander *commander){

    commander->AddCommand("Play", new PlayCommand());
    commander->AddCommand("play", new PlayCommand());
    commander->AddCommand("Pause",new PauseCommand());
    commander->AddCommand("pause",new PauseCommand());
    commander->AddCommand("Previous", new PreviousCommand());
    commander->AddCommand("previous", new PreviousCommand());
    commander->AddCommand("Next", new NextCommand());
    commander->AddCommand("next", new NextCommand());
    commander->AddCommand("Stop", new StopCommand());
    commander->AddCommand("stop", new StopCommand());
}
