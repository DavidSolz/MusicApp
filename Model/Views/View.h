#ifndef _VIEW_H
#define _VIEW_H
#include<string>
#include<iostream>
#include <sys/ioctl.h>
#include<termios.h>
#include<unistd.h>
#include<stdio.h>

#include "Item.h"
#pragma once


class View{
public: 

    View(const std::string &header, const std::string &footer);

    void PrintHeader();

    void PrintFooter();

    virtual void Render() = 0; 

    void SetNextView(const View* view);

    char GetChar();

    View* GetNextState();

protected:

View *nextState;
std::string headerLine;
std::string footerLine;

struct winsize w;

Item<View*> *menuItems;
int selected;
int optionCount;

};


#endif