#pragma once 

#include <iostream>
#include <string>
#include <iomanip>

typedef std::string String;

class Process {
private:
    int pid;
    String type;
    String process_name;
    int gpu_memory_usage;
public:
    Process(int pid, const String& type, const String& process_name, int gpu_memory_usage);
    ~Process() = default;

    void display() const;
};
