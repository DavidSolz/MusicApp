#include "Views/ViewController.h"

#pragma once

int main(int argc, char* argv[]){

    AudioEffectPipeline * pipeline = new AudioEffectPipeline();

    Player *player = new Player(argv[0],pipeline);

    ViewController *controller = new ViewController(player);

    while(controller->GetCurrentView()!=NULL){
        controller->Render();
    }

    player->Stop();
    printf("Have a nice day !    \n");

    delete controller;

    return 0;
}
