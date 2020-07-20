/*
 * LogTools // v1.0 // small and simple cross-platform logging toolset.
 * ************   https://github.com/SeppahBaws/logtools   ************
 *
 * -----------------------------[   LICENSE   ]-----------------------------
   MIT License
   
   Copyright (c) 2020 Seppe Dekeyser
   
   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:
   
   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.
   
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
 * -----------------------------[ END LICENSE ]-----------------------------
 *
 * ----- HOW TO USE -----

	Simply include logtools.h into your project.
	Initialize the logger by calling
		Logger::Init();

	Then you can use the logging functions like this:
		Logger::Log(LogLevel::Info, "Hello World");

	or you can use the other logging functions:
		Logger::LogInfo("Hello Info");
		Logger::LogWarning("Hello Warning");
		Logger::LogError("Hello Error");

 * ----- END HOW TO -----
 *
 * For more info you can check out the README.
 *
 */

#ifndef INCLUDE_LOGTOOLS_H
#define INCLUDE_LOGTOOLS_H

// Check if C++17 or greater, by checking if we have a C++17 specific feature.
#if __cpp_inline_variables < 201606
#error Incorrect C++ version. Logtools requires C++ version 17 or greater.
#endif

////////////////// Colors //////////////////
#if defined(__linux__)
// Linux Colors

#define BLACK      "\033[30m"
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define YELLOW     "\033[33m"
#define BLUE       "\033[34m"
#define MAGENTA    "\033[35m"
#define CYAN       "\033[36m"
#define WHITE      "\033[37m"

#define RESET      "\033[0m"

#elif defined(_WIN32) || defined(_WIN64)
// Windows Colors

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define BLACK      0
#define RED        FOREGROUND_INTENSITY | FOREGROUND_RED
#define GREEN      FOREGROUND_INTENSITY | FOREGROUND_GREEN
#define YELLOW     FOREGROUND_INTENSITY | FOREGROUND_RED   | FOREGROUND_GREEN
#define BLUE       FOREGROUND_INTENSITY | FOREGROUND_BLUE
#define MAGENTA    FOREGROUND_INTENSITY | FOREGROUND_RED   | FOREGROUND_BLUE
#define CYAN       FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE
#define WHITE      FOREGROUND_INTENSITY | FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_BLUE

#define RESET      FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE

#endif

//////////////// Main Logger ////////////////
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
#if defined(_WIN32) || defined(_WIN64)
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
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
#if defined(__linux__)
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
#elif defined(_WIN32) || defined(_WIN64)
	// Windows specific
	static void ResetConsoleColors()
	{
		SetConsoleTextAttribute(Instance().hConsole, RESET);
	}
	static void LogColor(const std::string& msg, const WORD color)
	{
		SetConsoleTextAttribute(Instance().hConsole, color);
		std::cout << msg << std::endl;
		ResetConsoleColors();
	}
#endif

	static Logger Instance()
	{
		static Logger instance{};
		return instance;
	}

private:
#if defined(_WIN32) || defined(_WIN64)
	inline static HANDLE hConsole;
#endif
};

#endif //INCLUDE_LOGTOOLS_H
