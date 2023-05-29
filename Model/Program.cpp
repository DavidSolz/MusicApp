
#include "Commander.h"
#include "PlayCommand.h"
#include "PauseCommand.h"
#include "StopCommand.h"
#include "EditCommand.h"
#include "NextCommand.h"
#include "HelpCommand.h"
#include "PreviousCommand.h"
#include <cstring>

#include "Views/ViewController.h"

#pragma once

int main(int argc, char* argv[]){

    AudioEffectPipeline * pipeline = new AudioEffectPipeline();

    Player *player = new Player(argv[0],pipeline);

    Commander *commander = new Commander(player);

    ViewController *controller = new ViewController(player);

    while(controller->GetCurrentView()!=NULL){
        controller->Render();
    }
    commander->ExecuteCommand(new StopCommand());
    printf("Have a nice day !    \n");

    delete controller;
    delete commander;

    return 0;
}

// void RegisterCommands(Commander *commander){

//     commander->AddCommand("help", new HelpCommand());
//     commander->AddCommand("edit", new EditCommand());
//     commander->AddCommand("play", new PlayCommand());
//     commander->AddCommand("pause",new PauseCommand());
//     commander->AddCommand("previous", new PreviousCommand());
//     commander->AddCommand("next", new NextCommand());
//     commander->AddCommand("stop", new StopCommand());
// }
