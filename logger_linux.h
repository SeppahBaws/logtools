#pragma once
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
	static void Init() {}

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

		std::cout << RESET;
	}

	static void LogInfo(const std::string& msg)
	{
		std::cout << WHITE << "[INFO] " << msg << std::endl;
	}

	static void LogWarning(const std::string& msg)
	{
		std::cout << YELLOW << "[WARNING] " << msg << std::endl;
	}

	static void LogError(const std::string& msg)
	{
		std::cout << RED << "[ERROR] " << msg << std::endl;
	}
};