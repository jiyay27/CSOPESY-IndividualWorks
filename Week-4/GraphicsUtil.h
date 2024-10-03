#pragma once 

#include <string>
#include <vector>
#include <Windows.h>
#include "Process.h"

class GraphicsUtil {
private:
    String name;
    String driver_version;
    int utilization;          
    int memory_usage;       
    int total_memory;        
    std::vector<Process> processes; 

    void setCursorPosition(int x, int y) const;
    void setConsoleTextColor(WORD color) const;

public:
    GraphicsUtil(const std::string& name, const std::string& driver_version, int utilization, int memory_usage, int total_memory);
    ~GraphicsUtil() = default;

    void addProcess(const Process& process);
    void displaySummary() const;
    void displayProcesses() const;
    void executeNvidiaSmi() const;
};