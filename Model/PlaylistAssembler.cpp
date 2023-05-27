#include "PlaylistAssembler.h"

namespace fs = std::filesystem;

void PlaylistAssembler::ClearTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void PlaylistAssembler::ExploreDirectory(const std::string& path, const std::vector<std::string> selected) {
    for (const auto& entry : fs::directory_iterator(path)) {
        const auto& entryPath = entry.path();
        std::string fileName = entryPath.filename().string();
        if(fs::is_directory(entryPath)){
            std::cout<<"[D] ";
        }else{
            if(std::find(selected.begin(),selected.end(), entryPath.string())!=selected.end()){
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

            auto it = std::find(selectedFiles.begin(), selectedFiles.end(), filePath);
            if (it != selectedFiles.end()) {
                selectedFiles.erase(it);
                std::cout << "File unmarked: " << filePath << std::endl;
            } else {
                selectedFiles.push_back(filePath);
                std::cout << "File marked: " << filePath << std::endl;
            }



        }else if(param=="done"){
            ClearTerminal();
            break;
        }else{
            ClearTerminal();
            std::cerr<<"Invalid command. Press any key to continue...\n";
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