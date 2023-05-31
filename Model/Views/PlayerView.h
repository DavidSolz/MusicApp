#ifndef _PLAYERVIEW_H
#define _PLAYERVIEW_H

#include "View.h"
#include "../Player.h"

#include <thread>
#include <chrono>

#pragma once;

class PlayerView: public View{
public:

PlayerView(const Player *player);

void QueuePrint(const Playlist* queue);

void Render();
    
private:

bool Running;
bool ToUpdate;
void ScreenRefreshF(SoundStream *stream, Playlist *queue);


Player * player;
bool input;
 
};
#endif