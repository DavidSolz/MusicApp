#include "PlaylistAssembler.h"

namespace fs = std::filesystem;

void PlaylistAssembler::ClearTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void PlaylistAssembler::ExploreDirectory(const std::string& path, const std::vector<track*> &selected) {

    std::cout << "Current Directory: " << path << std::endl;
    for (const auto& entry : fs::directory_iterator(path)) {
        const auto& entryPath = entry.path();
        std::string fileName = entryPath.filename().string();

        if(fileName[0]=='.')continue;

        if(fs::is_directory(entryPath)){
            std::cout<<"[D] ";
        }else{

            auto it = std::find_if(selected.begin(),selected.end(), [entryPath](track * t){ return t->GetPath()==entryPath;});

            if(it!=selected.end()){
                std::cout<<"[x] ";
            }else{
                std::cout<<"[F] ";
            }

        }
        std::cout << fileName << std::endl;
    }

    std::cout<<"\n==========Selected==========\n";
    for(const auto &item : selected){
        std::cout<<item->GetPath()<<"\n";
    }
    std::cout<<"============================\n";

}


void PlaylistAssembler::WavCrawler(std::vector<track*> &selected, const std::string crawlPath){
    
    try {
        for (const auto& entry : fs::recursive_directory_iterator(crawlPath)) {
            const auto& entryPath = entry.path();
            std::string fileName = entryPath.filename();
            if(fileName[0]=='.')continue;

            if (entry.is_regular_file() && entry.path().extension() == ".wav") {
                selected.push_back(new track(fileName, entryPath));
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error accessing folder: " << e.what() << std::endl;
    }

}

void PlaylistAssembler::FileExplorer(Playlist * playlist){
    std::stack<std::string> previousDirs;
    std::string filePath;

    std::vector<track*> tracks = playlist->GetTracks();

    ClearTerminal();

    while (true) {
        
        ExploreDirectory(directoryPath, tracks);

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
            
            track *t = NULL;

            for(const auto &element : tracks){
                if(element->GetPath()==filePath){
                    t = element;
                    break;
                }
            }

            if (t!=NULL) {
                tracks.erase(std::remove_if(tracks.begin(), tracks.end(),
                               [filePath](track *item){ return item->GetPath()==filePath;} ),tracks.end());
            } else {
                std::string name  = fs::path(filePath).filename().string();
                tracks.push_back(new track(name,filePath));
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

    playlist->SetTracks(tracks);

    std::cout<<"Files stored succesfully\n";

}