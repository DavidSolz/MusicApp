#ifndef _PLAYLISTASSEMBLER_H
#define _PLAYLISTASSEMBLER_H
#include<filesystem>
#include<stack>
#include<vector>
#include<iostream>
#include<algorithm>
#include "Playlist.h"
#pragma once

class PlaylistAssembler{
public:

void ClearTerminal();

void ExploreDirectory(const std::string& path, const std::vector<track*> &selected);

void FileExplorer(Playlist * selected);

private:

std::string directoryPath = ".";

};

#endif