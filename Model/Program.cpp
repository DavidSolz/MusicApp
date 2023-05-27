
#include "Commander.h"
#include "PlayCommand.h"
#include "PauseCommand.h"
#include "StopCommand.h"
#include "PlaylistAssembler.h";

int main(int argc, char* argv[]){

    Player *p = new Player(argv[0]);
    Commander *c = new Commander(p);

    c->AddCommand("Play", new PlayCommand());
    c->AddCommand("Pause",new PauseCommand());
    c->AddCommand("Stop", new StopCommand());

    PlaylistAssembler assembler;

    
    std::vector<std::string> selectedFiles = assembler.FileExplorer();
    
    delete c;
    delete p;

    return 0;
}