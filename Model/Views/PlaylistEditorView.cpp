#include "PlaylistEditorView.h"


PlaylistEditorView::PlaylistEditorView(const Playlist* playlist) : View(
    "EditorView",
    "Use arrow keys to select and item\n"
    "Press Enter to enter directory\n"
    "Press E to un/mark an item\n"
    "Press D to end editing"
    ){

    this->playlist=(Playlist*)playlist;
    this->assembler = new PlaylistAssembler();

}

void PlaylistEditorView::Render(){

    PrintHeader();
    std::vector<track*>tracks = playlist->GetTracks();

    for(const auto&track : tracks){
        printf("%s\n",track->GetName().c_str());
    }

    //assembler->FileExplorer(tracks);
    PrintFooter();

    while(true){
        if(GetChar()=='B')break;
    }


    SetNextView(this);
    
}