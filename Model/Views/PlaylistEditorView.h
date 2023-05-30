#ifndef _PLAYLISTEDITOR_H
#define _PLAYLISTEDIOTR_H

#include "View.h"
#include"../Player.h"
#include "../PlaylistAssembler.h"
#pragma once

class PlaylistEditorView : public View{
public:
PlaylistEditorView(const Playlist* playlist, const Player *player);

void Render();

private:

Playlist *playlist;
Player * player;
PlaylistAssembler *assembler;

};


#endif