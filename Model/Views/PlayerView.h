#ifndef _PLAYERVIEW_H
#define _PLAYERVIEW_H

#include "View.h"
#include "../Player.h"

#pragma once;

class PlayerView: public View{
public:

PlayerView(const Player *player);

void Render();
    
private:

static void Update(const Player *player, const View *view);

Player * player;
 
};
#endif