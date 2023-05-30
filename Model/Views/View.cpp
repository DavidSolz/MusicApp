#include "View.h"


View::View(const std::string &header, const std::string &footer){
    this->headerLine=header;
    this->footerLine=footer;
    SetNextView(this);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
}


char View::GetChar() {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);

    if (tcgetattr(0, &old) < 0) {
        perror("tcsetattr()");
    }

    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;

    if (tcsetattr(0, TCSANOW, &old) < 0) {
        perror("tcsetattr ICANON");
    }

    if (read(0, &buf, 1) < 0) {
        perror ("read()");
    }

    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;

    if (tcsetattr(0, TCSADRAIN, &old) < 0) {
        perror ("tcsetattr ~ICANON");
    }

    return buf;
}

void View::ClearConsole(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void View::PrintHeader(){

    
    
    for(int i=0; i<w.ws_col;i++){
        printf("=");
    }
    printf("\n");
    printf("%s \n", headerLine.c_str());
    for(int i=0; i<w.ws_col;i++){
        printf("=");
    }
    printf("\n");
}

void View::PrintFooter(){
    std::cout << "\033[" << 23 << ";" << 0 << "H"; 
    for(int i=0; i<w.ws_col;i++){
        printf("=");
    }
    printf("\n");
    printf("%s \n", footerLine.c_str());
    for(int i=0; i<w.ws_col;i++){
        printf("=");
    }
    printf("\n");
}


void View::SetNextView(const View* view){
    this->nextState=(View*)view;
}


View* View::GetNextState(){
    return nextState;
}