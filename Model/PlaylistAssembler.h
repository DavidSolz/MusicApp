#ifndef _PLAYLISTASSEMBLER_H
#define _PLAYLISTASSEMBLER_H
#include<filesystem>
#include<stack>
#include<vector>
#include<iostream>
#pragma once

class PlaylistAssembler{
public:

void ClearTerminal();

void ExploreDirectory(const std::string& path, const std::vector<std::string> selected);

std::vector<std::string> FileExplorer();

private:

std::string directoryPath = ".";

};

#endif