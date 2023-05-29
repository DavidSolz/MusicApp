#include "PlaylistView.h"



PlaylistView::PlaylistView(const Player *player) : View(
    "PlaylistView",
    "Press Esc to return to MenuView\n"
    "Use arrow keys to select an item\n"
    "Press E to enter playlist editor\n"
    "Press A to add new playlist\n"
    "Press I to enqueue playlist"
    ){
    this->player=((Player*) player);
    
}

void PlaylistView::EnqueuePlaylist(const Playlist *playlist){

    Playlist *queue = player->GetQueue();

    for(const auto &element : ((Playlist*)playlist)->GetTracks()){
        queue->Add(element);
    }

}

void PlaylistView::Render(){

    std::vector<Playlist*> items = player->GetList();
    selected=0;

    while(true){
    PrintHeader();

    for(int i = 0; i<items.size(); i++){
            if (selected == i) {
                    std::cout << "> " << items[i]->GetPlaylistName() << "\n";
            } else {
                    std::cout << items[i]->GetPlaylistName() << std::endl;
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
                        if (selected < items.size() - 1) {
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
    }else if(key=='i'){
        EnqueuePlaylist(items[selected]);
    }else if (key == '\n') {
        //PlaylistEditor
        break;
    }

    

    std::cout << "\033[2J";
    std::cout << "\033[H";    
    }
}


