#ifndef _TRACK_H
#define _TRACK_H

#include<string>

#pragma once

class track{
public:

/// @brief 
/// @param name 
/// @param path 
track(const std::string &name, const std::string path);

std::string GetName();
std::string GetPath();

private:
    std::string path;
    std::string name;
};


#endif