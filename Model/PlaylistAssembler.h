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

std::string GetRelativePath(const std::string& basePath, const std::string& fullPath);

void ExploreDirectory(const std::string& path, const std::vector<std::string> selected);

void FileExplorer(std::vector<std::string> &selectedFiles);

private:

std::string directoryPath = ".";

};

#endif