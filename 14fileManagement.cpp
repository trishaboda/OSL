// FILE MANAGEMENT
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdio.h>
using namespace std;
// Function to execute a command and read its output
string executeCommand(const char *command)
{
    char buffer[128];
    string result = "";
    FILE *pipe = _popen(command, "r");
    if (!pipe)
    {
        cerr << "Error executing command." << endl;
        return "";
    }
    while (!feof(pipe))
    {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    _pclose(pipe);
    return result;
}
int main()
{
    // Command to get memory information
    const char *command;
#ifdef _WIN32
    // For Windows operating system
    command = "systeminfo | findstr /C:\"Total Physical Memory\" /C:\"Available Physical Memory\"";
#elif __linux__ || __APPLE__
    // For Linux and macOS operating systems
    command = "free -h"; // You can also try "cat /proc/meminfo"
#else
    cout << "Operating system not supported." << endl;
    return 1;
#endif
    // Execute the command
    string output = executeCommand(command);
    // Display the output
    cout << "Memory Information:\n"
         << output << endl;
    return 0;
}