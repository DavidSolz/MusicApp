#include "PlayerView.h"

PlayerView::PlayerView(const Player *player): View(
    "PlayerView",
    "ESC - back to MenuView"
    ){
    this->player = ((Player *) player);
}

void PlayerView::Update(const Player *player, const View* view){
    //TODO
}

void PlayerView::Render(){

    SoundStream *stream = ((Player*)player)->GetStream();
    Playlist *queue = player->GetQueue();

    while(true){
    
    PrintHeader();

    if(stream->isPlaying()){
        printf("%s", queue->GetCurrentName().c_str());
        printf("Elapsed time: %s",stream->timeElapsed().c_str());

    }else{
        printf("Nothing is playing\n");
    }
    
    PrintFooter();

    char key = GetChar();

        if(key=='\033' && GetChar()!='['){
            
            SetNextView(this);
            break;
        }

    std::cout << "\033[2J";
    std::cout << "\033[H";  
    }


}