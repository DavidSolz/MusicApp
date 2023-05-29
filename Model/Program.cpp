
#include "Commander.h"
#include "PlayCommand.h"
#include "PauseCommand.h"
#include "StopCommand.h"
#include "EditCommand.h"
#include "NextCommand.h"
#include "HelpCommand.h"
#include "PreviousCommand.h"
#include <cstring>

#include "ViewController.h"

#pragma once

void HandleCommands(const Commander *commander);

void RegisterCommands(Commander *commander);

int main(int argc, char* argv[]){

    AudioEffectPipeline * pipeline = new AudioEffectPipeline();

    Player *player = new Player(argv[0],pipeline);

    Commander *commander = new Commander(player);

    ViewController *controller = new ViewController();

    RegisterCommands(commander);

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    std::thread *commandThread = new std::thread(HandleCommands,commander);

    Playlist* queue = player->GetQueue();
    track *t = new track("Sample","/Users/solz/Desktop/MusicApp/Out/Sample.wav");
    queue->Add(t);



    commandThread->join();


    printf("Have a nice day !    \n");

    delete commander;
    //delete player;
    //delete pipeline;

    return 0;
}

void HandleCommands(const Commander *commander){
    std::string command;
    while(true){
        
        std::cout << "\033[" << 23 << ";" << 0 << "H"; //Sets cursor position
        std::cout << "\033[" << 23 << ";1H\033[K"; //Clears line
        std::cout<<"> ";
        std::cin>>command;
        std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c){ return std::tolower(c); });
        if(command=="exit"){
            ((Commander *)commander)->ExecuteCommand("Stop");
            break;
        }
        ((Commander*)commander)->ExecuteCommand(command);
    }
}

void RegisterCommands(Commander *commander){

    commander->AddCommand("help", new HelpCommand());
    commander->AddCommand("edit", new EditCommand());
    commander->AddCommand("play", new PlayCommand());
    commander->AddCommand("pause",new PauseCommand());
    commander->AddCommand("previous", new PreviousCommand());
    commander->AddCommand("next", new NextCommand());
    commander->AddCommand("stop", new StopCommand());
}
