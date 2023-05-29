#ifndef _MENUVIEW_H
#define _MENUVIEW_H
#include "View.h"
#include "PlayerView.h"
#include "OptionView.h"
#include "PlaylistView.h"
#include<iostream>

#pragma once

class MenuView: public View{
public:

MenuView(const Player *player);

void Render();
    
};


#endif