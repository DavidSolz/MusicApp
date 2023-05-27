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
    std::cout<<"done \n";
    std::cout<<"============================\n\n";

    std::cout << "Current Directory: " << path << std::endl;
    for (const auto& entry : fs::directory_iterator(path)) {
        const auto& entryPath = entry.path();
        std::string fileName = entryPath.filename().string();

        if(fileName[0]=='.')continue;

        if(fs::is_directory(entryPath)){
            std::cout<<"[D] ";
        }else{

            auto it = std::find(selected.begin(),selected.end(), entryPath.string());

            if(it!=selected.end()){
                std::cout<<"[x] ";
            }else{
                std::cout<<"[F] ";
            }

        }
        std::cout << fileName << std::endl;
    }

    std::cout<<"\n==========Selected==========\n";
    for(const auto &filePath : selected){
        std::cout<<filePath<<"\n";
    }
    std::cout<<"============================\n";

}

void PlaylistAssembler::FileExplorer(std::vector<std::string> &selectedFiles){
    std::stack<std::string> previousDirs;
    std::string filePath;

    ClearTerminal();

    while (true) {
        
        ExploreDirectory(directoryPath, selectedFiles);

        std::string param;

        std::cin>> param;
        if(param=="cd"){
            std::cin>> param;
        }else if(param=="mark"){
            std::cin>> param; 

            if(fs::is_directory(param)){
                ClearTerminal();
                std::cerr<<"Cannot mark whole directory\n";
                continue;
            }


            try{
                filePath = fs::canonical(fs::path(directoryPath) / param).string();
            }catch(const std::exception& e){
                ClearTerminal();
                std::cerr<<"No such file or directory\n";
                continue;
            }
            

            auto it = std::find(selectedFiles.begin(), selectedFiles.end(), filePath);
            if (it != selectedFiles.end()) {
                selectedFiles.erase(it);
            } else {
                selectedFiles.push_back(filePath);
            }



        }else if(param=="done"){
            ClearTerminal();
            break;
        }else{
            ClearTerminal();
            std::cerr<<"Invalid command\n";
            continue;
        }

        if (param == "..") {
            if (!previousDirs.empty()) {
                directoryPath = previousDirs.top();
                previousDirs.pop();
            }else{
                std::cerr<<"Already in home directory\n";
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

    std::cout<<"Files stored succesfully\n";

}