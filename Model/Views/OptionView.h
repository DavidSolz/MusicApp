#ifndef _OPTIONVIEW_H
#define _OPTIONVIEW_H

#include "View.h"
#include "../Player.h"

#pragma once

class OptionView : public View{
public:

OptionView(const Player *player);

void Clamp(float &value,const int &index);

void Render();

private:
Player *player;
Item<float> *options;
};


#endif