#include "GraphicsUtil.h"
#include "Utility.h"
#include <iostream>
#include <iomanip>
#include <windows.h>

GraphicsUtil::GraphicsUtil(const std::string& name, const std::string& driver_version, int utilization, int memory_usage, int total_memory)
    : name(name), driver_version(driver_version), utilization(utilization), memory_usage(memory_usage), total_memory(total_memory) {}

void GraphicsUtil::setCursorPosition(int x, int y) const 
{
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GraphicsUtil::setConsoleTextColor(WORD color) const 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void GraphicsUtil::addProcess(const Process& process) 
{
    processes.push_back(process);
}

void GraphicsUtil::displaySummary() const 
{
    String truncatedGpu = Utility::truncateRightLine(name, 20);
    setConsoleTextColor(FOREGROUND_RED);
    setCursorPosition(0, 1);
    std::cout << "+-----------------------------------------------------------------------------+\n";
    std::cout << "| NVIDIA-SMI 528.49" << std::setw(25) << "Driver Version: " << driver_version << std::setw(23) << "CUDA Version: 12.0" << std::setw(6) << "|" <<std::endl;
    std::cout << "|-------------------------------+----------------------+----------------------|\n";
    std::cout << "| GPU Name             TCC/WDDM | Bus-Id" << std::setw(17) << "Disp.A | " << "Volatile Uncorr. ECC |\n";
    std::cout << "| Fan Temp  Perf  Pwr:Usage/Cap |         Memory-Usage | " << "GPU-Util  Compute M. " << std::setw(2) << "|\n";
    std::cout << "|" << std::setw(32) << "|" << std::setw(23) << "|" << std::setw(24) << "MIG M. |\n";
    std::cout << "|=============================================================================+\n";
    std::cout << "|   0 " << truncatedGpu << std::setw(10) << " WDDM | 00000000:01:00.0  On |                  N/A |\n";
    std::cout << "| N/A   75C    P3     13W / 62W |   1667MiB /  4096MiB |     25%      Default |\n";
    std::cout << "|                               |                      |                  N/A |\n";
    std::cout << "+-------------------------------+----------------------+----------------------+\n";

    // unused-vars
    // 1. utilization
    // 2. memory_usage
    // 3. total_memory
}

void GraphicsUtil::displayProcesses() const
{
    setCursorPosition(0, 13); // Move below the GPU summary
    std::cout << "+-------+-------+------------------------------------------+------------------+" << std::endl;
    std::cout << "| PID   | Type  | Process Name                             | GPU Memory Usage |" << std::endl;
    std::cout << "+-------+-------+------------------------------------------+------------------+" << std::endl;

    for (const auto& process : processes) {
        process.display();
    }

    std::cout << "+-------+-------+------------------------------------------+------------------+" << std::endl;
}