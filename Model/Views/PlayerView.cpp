#include "PlayerView.h"

PlayerView::PlayerView(const Player *player): View(
    "PlayerView",
    "Press Esc to return to MenuView\n"
    "Press P to play\n"
    "Press S to stop\n"
    "Press T to Pause\n"
    "Press C to clear the queue\n"
    "Press L to enable loop mode"
    ){
    this->player = ((Player *) player);
}

void PlayerView::Update(const SoundStream *stream){

}

void PlayerView::QueuePrint(const Playlist* queue){
    std::cout << "\033[" << 15 << ";" << 0 << "H"; 
    for(int i=0; i<w.ws_col;i++){
        printf("=");
    }
    printf("QueueView\n");
    for(int i=0; i<w.ws_col;i++){
        printf("=");
    }
    printf("\n");
    
    std::vector<track*> tracks = ((Playlist*)queue)->GetTracks();

    if(tracks.size()==0){
        printf("Queue is empty\n");
    }else{
        for(int i=0; i<tracks.size() && i<5; i++){
            printf("%s \n",tracks[i]->GetName().c_str());
        }
    }

    for(int i=0; i<w.ws_col;i++){
        printf("=");
    }
    printf("\n");
}

void PlayerView::Render(){

    SoundStream *stream = ((Player*)player)->GetStream();
    Playlist *queue = player->GetQueue();

    while(true){
    
    PrintHeader();

    if(stream->isPlaying()){
        printf("%s\n", queue->GetCurrentName().c_str());
        printf("Elapsed time: %s",((SoundStream*)stream)->timeElapsed().c_str());

    }else{
        printf("Nothing is playing\n");
    }
    

    QueuePrint(queue);

    PrintFooter();

    char key = GetChar();

        if(key=='\033' && GetChar()!='['){
            SetNextView(this);
            break;
        }else if(key=='p'){
            player->Play();
        }else if(key=='s'){
            player->Stop();
        }else if(key=='t'){
            player->Pause();
        }

    ClearConsole();
    }


}