#pragma once
#if defined(_WIN32) || defined(_WIN64)

#include "logcolors.h"

#include <string>
#include <iostream>

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

		ResetConsoleColors();
	}

	static void LogInfo(const std::string& msg)
	{
		LogColor("[INFO] " + msg, WHITE);
	}

	static void LogWarning(const std::string& msg)
	{
		LogColor("[WARNING] " + msg, YELLOW);
	}

	static void LogError(const std::string& msg)
	{
		LogColor("[ERROR] " + msg, RED);
	}

private:
	// Windows specific
	static void ResetConsoleColors()
	{
		SetConsoleTextAttribute(Instance().hConsole, RESET);
	}
	static void LogColor(const std::string& msg, const int color)
	{
		SetConsoleTextAttribute(Instance().hConsole, color);
		std::cout << msg << std::endl;
		ResetConsoleColors();
	}

	static Logger Instance()
	{
		static Logger logger{};
		return logger;
	}
	
private:
	static HANDLE hConsole;
};

#endif
