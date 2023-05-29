#ifndef _PLAYLISTVIEW_H
#define _PLAYLISTVIEW_H

#include "View.h"
#include "../Player.h"

#pragma once

class PlaylistView: public View{
public:

PlaylistView(const Player *player);

void Render();
    
private:

Player *player;
int selected;

};


#endif