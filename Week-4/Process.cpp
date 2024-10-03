#include "Process.h"

typedef std::string String;

Process::Process(int pid, const String& type, const String& process_name, int gpu_memory_usage)
    : pid(pid), type(type), process_name(process_name), gpu_memory_usage(gpu_memory_usage) {}

void Process::display() const {
    std::cout << "| " << std::setw(5) << pid << " | "
                  << std::setw(5) << type << " | "
                  << std::setw(20) << process_name << " | "
                  << std::setw(15) << gpu_memory_usage << " MB |" << std::endl;
}