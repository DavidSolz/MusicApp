#include "PlayerView.h"

PlayerView::PlayerView(const Player *player): View(
    "PlayerView",
    "Press Esc to return to MenuView\n"
    "Press P to play\n"
    "Press S to stop\n"
    "Press N to next\n"
    "Press T to Pause\n"
    "Press F to skip by x seconds\n"
    "Press C to clear the queue"
    ){
    this->player = ((Player *) player);
    Running = false;
    input=false;
}

void PlayerView::ScreenRefreshF(SoundStream *stream, Playlist *queue){
    char counter = 0;
    while (Running) {
        if (ToUpdate){
            ClearConsole();
            PrintHeader();

            track *t = queue->GetCurrentTrack();

            if(stream->isPlaying() && t!=NULL){
                printf("%s\n", t->GetName().c_str());
                printf("Elapsed time: %s\n",((SoundStream*)stream)->timeElapsed().c_str());

            }else{
                printf("Nothing is playing\n");
            }

            printf("Loop mode : %s\n",player->isLooping()==true?"enabled":"disabled");

            QueuePrint(queue);

            PrintFooter();
            ToUpdate = false;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (stream->isPlaying() && input==false){
            if (counter == 9){
                counter = 0;
                ToUpdate = true;
            } else {
                counter++;
            }
        }
    }
}

void PlayerView::QueuePrint(const Playlist* queue){
    std::cout << "\033[" << 15 << ";" << 0 << "H"; 
    for(int i=0; i<w.ws_col;i++){
        printf("=");
    }
    printf("\nQueueView\n");
    for(int i=0; i<w.ws_col;i++){
        printf("=");
    }
    printf("\n");
    
    std::vector<track*> tracks = ((Playlist*)queue)->GetTracks();

    if(tracks.size()==0){
        printf("Queue is empty\n");
    }else{
        int index = ((Playlist*)queue)->GetCurrentIndex();
        for(int i=index; i<tracks.size(); i++){
            if(index==i){
                std::cout<<"> "<<tracks[i]->GetName()<<"\n";
            }else{
                std::cout<<tracks[i]->GetName()<<"\n";
            }
        }
    }

    for(int i=0; i<w.ws_col;i++){
        printf("=");
    }
    printf("\n");
}

void PlayerView::Render(){
    Running = true;

    SoundStream *stream = ((Player*)player)->GetStream();
    Playlist *queue = player->GetQueue();

    std::thread *refreshThread = new std::thread(&PlayerView::ScreenRefreshF, this, stream, queue);

    while(Running){

    ToUpdate = true;
    char key = GetChar();

        if(key=='\033' && GetChar()!='['){
            SetNextView(this);
            Running=false;
            break;
        }else if(key=='p'){
            player->Play();
        }else if(key=='s'){
            player->Stop();
        }else if(key=='t'){
            player->Pause();
        }else if(key=='c'){
            player->ClearQueue();
        }else if(key=='n'){
            player->Next();
        }else if(key=='f'){
            int time=0;
            input=true;
            std::cout<<"Seconds to skip: ";
            std::cin>>time;
            player->Skip(time);
            input=false;
        }
    }

    if(refreshThread->joinable())refreshThread->join();
    delete refreshThread;


}