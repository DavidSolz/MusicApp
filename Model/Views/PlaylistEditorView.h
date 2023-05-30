#ifndef _PLAYLISTEDITOR_H
#define _PLAYLISTEDIOTR_H

#include "View.h"
#include "../PlaylistAssembler.h"
#pragma once

class PlaylistEditorView : public View{
public:
PlaylistEditorView(const Playlist* playlist);

void Render();

private:

Playlist *playlist;
PlaylistAssembler *assembler;

};


#endif