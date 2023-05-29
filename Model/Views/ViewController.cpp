#include "ViewController.h"

ViewController::ViewController(const Player *player){
    this->player = (Player*)player;
    menu = new MenuView();
    views.push(menu);
}

View * ViewController::GetCurrentView(){
    return views.top();
}

void ViewController::disableInputBuffering() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void ViewController::enableInputBuffering() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void ViewController::Render(){

    View * view = GetCurrentView();

    if(view==NULL) return;

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    disableInputBuffering();

    view->Render();

    enableInputBuffering();

    View * newView = view->GetNextState();

    if(newView==NULL){
        views.push(NULL);
        return;
    }

    if(newView==view){

        if(views.size()>1){
            views.pop();
        }
        return;
    }else{
        views.push(newView);
    }



}