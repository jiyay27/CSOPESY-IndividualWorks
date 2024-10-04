#include <iostream>
#include <string>
#include "MarqueeConsole.h"

typedef std::string String;
using std::cout;
using std::cin;

void black(){
    cout << "\033[0;30m";
}
void red(){
    cout << "\033[0;31m";
}
void green(){
    cout << "\033[0;32m";
}
void yellow(){
    cout << "\033[0;33m";
}
void blue(){
    cout << "\033[0;34m";
}
void purple(){
    cout << "\033[0;35m";
}
void cyan(){
    cout << "\033[0;36m";
}
void white(){
    cout << "\033[0;37m";
}

void asciiart(){
    cout << "  _____  _____  ____  _____  ______  _______     __ \n";
    cout << " / ____|/ ____|/ __ \\|  __ \\|  ____|/ ____\\ \\   / / \n";
    cout << "| |    | (___ | |  | | |__) | |__  | (___  \\ \\_/ /  \n";
    cout << "| |     \\___ \\| |  | |  ___/|  __|  \\___ \\  \\   /   \n";
    cout << "| |____ ____) | |__| | |    | |____ ____) |  | |    \n";
    cout << " \\_____|_____/ \\____/|_|    |______|_____/   |_|    \n";
}
void header(){
    green();
    cout << "Hello, Welcome to CSOPESY commandline!\n";
    yellow();
    cout << "Type 'exit' to quit, 'clear' to clear the screen\n";
    white();
}
void clear(){
    system("cls");
    asciiart();
    header();
}

int main() {

    asciiart();
    header();
    String response = "";

    bool running = true;
    while(running)
    {
        cout << "Enter a command: ";
        cin >> response;

        if(response == "exit")
        {
            return 0;
        } else if(response == "clear")
        {
            clear();
        } else if(response == "marquee")
        {
            while(true) {
                pollKeyboard();
                usleep(3000);
                drawScreen();
            }
        }
    }
    return 0;
}