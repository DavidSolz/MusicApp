#include "OptionView.h"




OptionView::OptionView() : View(
    "OptionHeader",
    "ESC - back to MenuView"
    ){

}

void OptionView::Render(){
    while(true){
    PrintHeader();


    printf("Content\n");

    PrintFooter();
    char key = GetChar();

    if(key=='\033' && GetChar()!='['){
        SetNextView(this);
        break;
    }

    ClearConsole();  
    }
}