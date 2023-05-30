#ifndef _PLAYLISTVIEW_H
#define _PLAYLISTVIEW_H

#include "View.h"
#include "PlaylistEditorView.h"
#include "../Player.h"

#pragma once

class PlaylistView: public View{
public:

PlaylistView(const Player *player);

void Render();
    
void EnqueuePlaylist(const Playlist *playlist);

private:

Player *player;
int selected;

};


#endif