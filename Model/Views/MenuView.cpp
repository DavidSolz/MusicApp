#include "MenuView.h"


MenuView::MenuView(const Player *player) : View(
    "MenuView",
    "Use arrow keys to select an item\nTo accept your selection press Enter"){
    this->optionCount=4;
    menuItems = new Item<View*>[optionCount];
    menuItems[0] = Item<View*>("Player",new PlayerView(player));
    menuItems[1] = Item<View*>("Playlists",new PlaylistView(player));
    menuItems[2] = Item<View*>("Options",new OptionView());
    menuItems[3] = Item<View*>("Exit", NULL);
}

void MenuView::Render(){

    this->selected=0;

    while (true) {

    PrintHeader();
        for (int i = 0; i < optionCount; ++i) {
            if (selected == i) {
                std::cout << "> " << menuItems[i].name << "\n";
            } else {
                std::cout << menuItems[i].name << std::endl;
            }
        }
    PrintFooter();

        char key = GetChar();

        
        if (key == '\033') {  
            GetChar();  
            key = GetChar();  

            switch (key) {
                case 'A': 
                    if (selected > 0) {
                        selected--;
                    }
                    break;
                case 'B': 
                    if (selected < optionCount - 1) {
                        selected++;
                    }
                    break;
                default:
                    break;
            }
        } else if (key == '\n') {
            SetNextView(menuItems[selected].item);
            break;
        }
        
        std::cout << "\033[2J";
        std::cout << "\033[H";
    }
}
