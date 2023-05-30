#include "PlaylistEditorView.h"


PlaylistEditorView::PlaylistEditorView(const Playlist* playlist, const Player* player) : View(
    "EditorView",
    "Use arrow keys to select and item\n"
    "Press Esc to return to PlaylistView\n"
    "Press D to delete track\n"
    "Press I to add track to queue\n"
    "Press E to enter edit mode\n"
    ){

    this->playlist=(Playlist*)playlist;
    this->player=(Player*)player;
    this->assembler = new PlaylistAssembler();

}

void PlaylistEditorView::Render(){

    Playlist*queue = player->GetQueue();

    while(true){
    PrintHeader();
    std::vector<track*>tracks = playlist->GetTracks();

    for(int i=0; i<tracks.size();i++){
        if(selected==i){
            printf("> %s\n",tracks[i]->GetName().c_str());
        }else{
            printf("%s\n",tracks[i]->GetName().c_str());
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
    }else if(key=='e'){
        assembler->FileExplorer(playlist);
    }else if(key=='i'){
        queue->Add(tracks[selected]);
    }else if(key=='d'){
       tracks.erase(tracks.begin()+selected);
    }


    ClearConsole();
    }

    


    SetNextView(this);
    
}