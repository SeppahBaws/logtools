#pragma once
#include "logcolors.h"

#include <string>
#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

enum LogLevel
{
    Info = 0x1,
    Warning = 0x2,
    Error = 0x4
};

class Logger
{
public:
    static void Init()
    {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    static void Log(LogLevel level, const std::string& msg)
    {
        switch (level)
        {
        case LogLevel::Info:
            LogInfo(msg);
            break;

        case LogLevel::Warning:
            LogWarning(msg);
            break;

        case LogLevel::Error:
            LogError(msg);
            break;
        }

        SetConsoleTextAttribute(hConsole, RESET);
    }

    static void LogInfo(const std::string& msg)
    {
        SetConsoleTextAttribute(hConsole, RESET);
        std::cout << "[INFO] " << msg << std::endl;
    }

    static void LogWarning(const std::string& msg)
    {
        SetConsoleTextAttribute(hConsole, YELLOW);
        std::cout << "[WARNING] " << msg << std::endl;
    }

    static void LogError(const std::string& msg)
    {
        SetConsoleTextAttribute(hConsole, RED);
        std::cout << "[ERROR] " << msg << std::endl;
    }

private:
    HANDLE hConsole;
};
