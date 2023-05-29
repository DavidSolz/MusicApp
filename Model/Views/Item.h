#ifndef _ITEM_H
#define _ITEM_H

template<class T>
struct Item{
    std::string name;
    T item;

    Item(){
        
    }

    Item(const std::string &name, const T item){
        this->name=name;
        this->item=(T)item;
    }
};

#endif