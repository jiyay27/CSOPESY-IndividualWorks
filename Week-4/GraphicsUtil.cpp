#include "GraphicsUtil.h"
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

void GraphicsUtil::addProcess(const Process& process) 
{
    processes.push_back(process);
}

void GraphicsUtil::displaySummary() const 
{
    setCursorPosition(0, 6);
    std::cout << "+---------------------------------------------------------------+" << std::endl;
    std::cout << "| GPU Name: " << std::setw(55) << name << " |" << std::endl;
    std::cout << "| Driver Version: " << std::setw(47) << driver_version << " |" << std::endl;
    std::cout << "| GPU Utilization: " << std::setw(45) << utilization << "% |" << std::endl;
    std::cout << "| GPU Memory Usage: " << std::setw(27) << memory_usage << " MB / " << total_memory << " MB |" << std::endl;
    std::cout << "+---------------------------------------------------------------+" << std::endl;
}

void GraphicsUtil::displayProcesses() const 
{
    setCursorPosition(0, 12); // Move below the GPU summary
    std::cout << "+-------+-------+----------------------+-----------------+" << std::endl;
    std::cout << "| PID   | Type  | Process Name          | GPU Memory Usage|" << std::endl;
    std::cout << "+-------+-------+----------------------+-----------------+" << std::endl;

    for (const auto& process : processes) {
        process.display();
    }

    std::cout << "+-------+-------+----------------------+-----------------+" << std::endl;
}