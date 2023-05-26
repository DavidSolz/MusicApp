#include "track.h"


track::track(const std::string &name, const std::string path){
    this->name=name;
    this->path=path;
}

std::string track::GetName(){
    return name;
}

std::string track::GetPath(){
    return path;
}