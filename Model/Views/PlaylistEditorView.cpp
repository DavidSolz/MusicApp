#include "PlaylistEditorView.h"


PlaylistEditorView::PlaylistEditorView(const Playlist* playlist, const Player* player) : View(
    "EditorView",
    "Use arrow keys to select and item\n"
    "Press Esc to return to PlaylistView\n"
    "Press D to delete track\n"
    "Press I to add track to queue\n"
    "Press E to enter edit mode\n"
    "Press P to play\n"
    "Press S to stop"
    ){

    this->playlist=(Playlist*)playlist;
    this->player=(Player*)player;
    this->assembler = new PlaylistAssembler();

}

void PlaylistEditorView::Render(){

    Playlist*queue = player->GetQueue();
    std::vector<track*>tracks = playlist->GetTracks();
    SoundStream *stream = player->GetStream();
    selected=0;


    while(true){
    PrintHeader();

    for(int i=0; i<tracks.size();i++){
        if (selected == i) {
                std::cout << "> " << tracks[i]->GetName() << "\n";
            } else {
                std::cout << tracks[i]->GetName() << std::endl;
            }
    }

    PrintFooter();

    char key = GetChar();

    if (key == '\033') { 
            
            if (GetChar() == '[') {
                char arrowKey = GetChar();
                switch (arrowKey) {
                    case 'A': 
                        if (selected > 0) {
                            selected--;
                        }
                        break;
                    case 'B': 
                        if (selected < tracks.size() - 1) {
                            selected++;
                        }
                        break;
                    default:
                        break;
                }
            } else { 
                SetNextView(this);
                break;
            }
    }else if(key=='p'){
        if(stream->isPlaying()){
            stream->stop();
        }
        stream->init(tracks[selected]->GetPath());
        stream->play();

    }else if(key=='s'){
        if(stream->isPlaying()){
            stream->stop();
        }
    }else if(key=='e'){
        assembler->FileExplorer(playlist);
        tracks = playlist->GetTracks();
    }else if(key=='i'){
        if(tracks.size()==0)break;
        queue->Add(tracks[selected]);
    }else if(key=='d'){
        if(tracks.size()==0)return;
        tracks.erase(tracks.begin()+selected);
        if(selected>=tracks.size()){
            selected=0;
        }
        playlist->SetTracks(tracks);
    }

    
    ClearConsole();
    }

    if(stream->isPlaying()){
            stream->stop();
    }
    SetNextView(this);
    
}