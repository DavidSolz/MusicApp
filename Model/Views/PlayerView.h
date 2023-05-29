#ifndef _PLAYERVIEW_H
#define _PLAYERVIEW_H

#include "View.h"
#include "../Player.h"

#pragma once;

class PlayerView: public View{
public:

PlayerView(const Player *player);

void QueuePrint(const Playlist* queue);

void Render();
    
private:

static void Update(const SoundStream *stream);

Player * player;
 
};
#endif