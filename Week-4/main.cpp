#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <Windows.h>

//#include "CustomLayout.h"
#include "Process.h"
#include "GraphicsUtil.h"

typedef std::string String;
using std::cout;
using std::cin;
using std::endl;

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

void showTimestamp() {
    SYSTEMTIME st;
    GetLocalTime(&st);

    const char* days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    
    const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    printf("%s %s %2d %02d:%02d:%02d %4d\n", 
        days[st.wDayOfWeek],     
        months[st.wMonth - 1],   
        st.wDay,                 
        st.wHour,                
        st.wMinute,             
        st.wSecond,              
        st.wYear);               
}

void runSMI() {
    AllocConsole();

    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);
    freopen_s(&fp, "CONOUT$", "w", stderr);

    GraphicsUtil GraphicsUtil("NVIDIA-SMI 528.49", "999.99", 65, 6144, 8192);

    GraphicsUtil.addProcess(Process(01, "C", "chrome.exe", 256));
    GraphicsUtil.addProcess(Process(02, "C", "notepad.exe", 128));
    GraphicsUtil.addProcess(Process(03, "G", "python.exe", 512));
    GraphicsUtil.addProcess(Process(04, "C", "vscode.exe", 1024));
    GraphicsUtil.addProcess(Process(05, "G", "tensorflow.exe", 2048));

    GraphicsUtil.displaySummary();
    GraphicsUtil.displayProcesses();

    std::cout << "\nPress any key to exit..." << std::endl;
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
        } else if(response == "nvidia-smi")
        {
            system("cls");  

            showTimestamp();

            GraphicsUtil graphicsUtil("NVIDIA RTX 4090 Laptop GPU", "999.99", 65, 6144, 8192);
            
            graphicsUtil.displaySummary();
            
            graphicsUtil.addProcess(Process(01, "G", "reallylongprocess/name/test/123/456/valorant.exe", 256));
            graphicsUtil.addProcess(Process(02, "G", "another/really/long/process/name/vscode.exe", 128));
            graphicsUtil.addProcess(Process(03, "C", "NASM.exe", 512));
            graphicsUtil.addProcess(Process(04, "C", "aiosehntoiase/asoiehcnas/aoisehcnaoencaur/rubyonrails.exe", 1024));
            graphicsUtil.addProcess(Process(05, "C", "afterburner.exe", 2048));

            graphicsUtil.displayProcesses();
            
        }
    }
    

    return 0;
}