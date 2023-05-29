#ifndef _VIEWCONTROLLER_H
#define _VIEWCONTROLLER_H
#include<stack>
#include<list>
#include "MenuView.h"

typedef std::pair<std::string, View*> State;

class ViewController {
public:

ViewController();

void RegisterView(const std::string &name, const View &view);

View* GetCurrentView();



private:

std::stack<View*> views;
std::list<State*> states;


};


#endif