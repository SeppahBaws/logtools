#pragma once
#if defined(__linux__)

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
	// Linux specific
	static void ResetConsoleColors()
	{
		std::cout << RESET;
	}
	static void LogColor(const std::string& msg, const std::string& color)
	{
		std::cout << color << msg << std::endl;
		ResetConsoleColors();
	}

	static Logger Instance()
	{
		static Logger logger{};
		return logger;
	}
};

#endif
