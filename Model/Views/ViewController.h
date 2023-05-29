#ifndef _VIEWCONTROLLER_H
#define _VIEWCONTROLLER_H
#include<stack>
#include<list>
#include "MenuView.h"
#include "../Player.h"

class ViewController {
public:

ViewController(const Player * player);

View* GetCurrentView();

void Render();

void disableInputBuffering();

void enableInputBuffering();

private:

std::stack<View*> views;
View *menu;
Player *player;

};


#endif