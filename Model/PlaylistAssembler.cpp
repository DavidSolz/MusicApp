#include "PlaylistAssembler.h"

namespace fs = std::filesystem;

void PlaylistAssembler::ClearTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

std::string PlaylistAssembler::GetRelativePath(const std::string& basePath, const std::string& fullPath) {
    fs::path base = fs::absolute(basePath);
    fs::path full = fs::absolute(fullPath);
    return fs::relative(full, base).string();
}


void PlaylistAssembler::ExploreDirectory(const std::string& path, const std::vector<std::string> selected) {
    std::cout<<"==========Commands==========\n";
    std::cout<<"mark filename \n";
    std::cout<<"cd [directory/..]\n";
    std::cout<<"============================\n";
    for (const auto& entry : fs::directory_iterator(path)) {
        const auto& entryPath = entry.path();
        std::string fileName = entryPath.filename().string();

        if(fileName[0]=='.')continue;

        std::string relativePath = GetRelativePath(path, entryPath);


        if(fs::is_directory(entryPath)){
            std::cout<<"[D] ";
        }else{

            if(std::find(selected.begin(),selected.end(), relativePath)!=selected.end()){
                std::cout<<"[X] ";
            }else{
                std::cout<<"[F] ";
            }

        }
        std::cout << fileName << std::endl;
    }
}

std::vector<std::string> PlaylistAssembler::FileExplorer(){
    std::stack<std::string> previousDirs;
    std::vector<std::string> selectedFiles;

    while (true) {
        std::cout << "Current Directory: " << directoryPath << std::endl;
        ExploreDirectory(directoryPath, selectedFiles);

        std::string param;

        std::cin>> param;
        if(param=="cd"){
            std::cin>> param;
        }else if(param=="mark"){
            std::cin>> param; 

            if(fs::is_directory(param)){
                ClearTerminal();
                std::cerr<<"Cannot mark whole directory. Press any key to continue...\n";
                getchar();
                continue;
            }

            const std::string filePath = fs::canonical(fs::path(directoryPath) / param).string();
            std::string relativePath = GetRelativePath(directoryPath,filePath);

            auto it = std::find(selectedFiles.begin(), selectedFiles.end(), relativePath);
            if (it != selectedFiles.end()) {
                selectedFiles.erase(it);
                std::cout << "File unmarked: " << relativePath << std::endl;
            } else {
                selectedFiles.push_back(relativePath);
                std::cout << "File marked: " << relativePath << std::endl;
            }



        }else if(param=="done"){
            ClearTerminal();
            break;
        }else{
            ClearTerminal();
            std::cerr<<"Invalid command\n";
            getchar();
            continue;
        }

        if (param == "..") {
            if (!previousDirs.empty()) {
                directoryPath = previousDirs.top();
                previousDirs.pop();
            } 
        } else {
            fs::path newPath = fs::canonical(fs::path(directoryPath) / param);
            if (fs::is_directory(newPath)) {
                previousDirs.push(directoryPath);
                directoryPath = newPath.string();
            }
        }

        ClearTerminal();
    }

    std::cout<<"Playlist stored succesfully\n";

    return selectedFiles;
}