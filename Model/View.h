#ifndef _VIEW_H
#define _VIEW_H
#include<string>

#pragma once

class View{

    View(const std::string &header, const std::string &footer);

    virtual void Render() = 0; 

private:

std::string headerLine;
std::string footerLine;

};


#endif