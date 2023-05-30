#include "OptionView.h"




OptionView::OptionView(const Player *player) : View(
    "OptionHeader",
    "Press Esc to back to MenuView\n"
    "Use arrow keys to select and modify an item"
    ){

    this->optionCount=2;
    this->selected=0;
    this->player=(Player*)player; 
    this->options = new Item<float>[optionCount];
    options[0] = Item<float>("Volume",1);
    options[1] = Item<float>("Balance",0);
}

void OptionView::Clamp(float &value,const int &index){

    AudioEffectPipeline *pipe = player->GetPipeline();

    if(index==0){

        if(value>1){
            value=1;
        }else if(value<0.1){
            value=0;
        }

        pipe->setEffect("volume",&value);

    }else if(index==1){
        if(value>1){
            value=1;
        }else if(value<-1){
            value=-1;
        }else if(value>-0.1 && value<0.1){
            value=0;
        }   

        pipe->setEffect("balance",&value);
    }
}

void OptionView::Render(){

    

    while(true){
    PrintHeader();

    for(int i=0; i<optionCount; i++){
        if(selected==i){
            std::cout<<"> "<<options[i].name<<"\t"<<options[i].item<<"\n";
        }else{
            std::cout<<options[i].name<<"\t"<<options[i].item<<"\n";
        }
    }

    PrintFooter();
    char key = GetChar();

    if (key == '\033') {  
            if(GetChar()=='['){  
                key = GetChar();  

                switch (key) {
                    case 'A': 
                        if (selected > 0) {
                            selected--;
                        }
                        break;
                    case 'B': 
                        if (selected < optionCount - 1) {
                            selected++;
                        }
                        break;
                    case 'C': 
                        options[selected].item+=0.1;
                        Clamp(options[selected].item,selected);
                        break;
                    case 'D': 
                        options[selected].item-=0.1;
                        Clamp(options[selected].item,selected);

                        break;
                    default:
                        break;
                }
            }else{
                SetNextView(this);
            break;
            }
        }

    ClearConsole();  
    }
}