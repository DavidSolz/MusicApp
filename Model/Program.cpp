
#include "Commander.h"
#include "PlayCommand.h"

int main(int argc, char* argv[]){

    Player *p = new Player();
    Commander *c = new Commander(p);

    c->AddCommand("Play", new PlayCommand());

    c->SetCommand("Play");
    c->ExecuteCommand();


    return 0;
}