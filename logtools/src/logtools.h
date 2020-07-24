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

// Platform definitions
#if defined(__linux__)
#define LOGTOOLS_LINUX
#elif defined(_WIN32) | defined(_WIN64)
#define LOGTOOLS_WINDOWS
#else
#error Unsupported platform! Logtools only works on Linux or Windows.
#endif

// Check if C++17 or greater, by checking if we have a C++17 specific feature.
#if __cpp_inline_variables < 201606
#error Incorrect C++ version. Logtools requires C++ version 17 or greater.
#endif

////////////////// Colors //////////////////
#if defined(LOGTOOLS_LINUX)
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

#elif defined(LOGTOOLS_WINDOWS)
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
#include <cstdio>
#include <cstdarg>

enum class LogLevel
{
	Trace = 0,
	Debug = 1,
	Info = 2,
	Warning = 3,
	Error = 4
};

struct LogBinding
{
	const char* identifier;
#if defined(LOGTOOLS_LINUX)
	const char* color;
#elif defined(LOGTOOLS_WINDOWS)
	WORD color;
#endif
};

class Logger
{
public:
	static void Init()
	{
#if defined(LOGTOOLS_WINDOWS)
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
	}

	static void SetLevel(LogLevel level)
	{
		m_LogLevel = level;
	}

	static void LogTrace(const std::string& msg)
	{
		Log(LogLevel::Trace, msg);
	}

	static void LogDebug(const std::string& msg)
	{
		Log(LogLevel::Debug, msg);
	}

	static void LogInfo(const std::string& msg)
	{
		Log(LogLevel::Info, msg);
	}

	static void LogWarning(const std::string& msg)
	{
		Log(LogLevel::Warning, msg);
	}

	static void LogError(const std::string& msg)
	{
		Log(LogLevel::Error, msg);
	}


	static void LogTrace(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		Log(LogLevel::Trace, fmt, args);
		va_end(args);
	}

	static void LogDebug(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		Log(LogLevel::Debug, fmt, args);
		va_end(args);
	}

	static void LogInfo(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		Log(LogLevel::Info, fmt, args);
		va_end(args);
	}

	static void LogWarning(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		Log(LogLevel::Warning, fmt, args);
		va_end(args);
	}

	static void LogError(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		Log(LogLevel::Error, fmt, args);
		va_end(args);
	}

private:
	static void Log(LogLevel level, const std::string& msg)
	{
		if (m_LogLevel > level) // If we have the logger's log level set higher than the current level, ignore the message.
			return;

		SetConsoleColor(m_Bindings[static_cast<int>(level)].color);
		std::cout << "[" << m_Bindings[static_cast<int>(level)].identifier << "] ";
		std::cout << msg << std::endl;
		ResetConsoleColor();
	}

	static void Log(LogLevel level, const char* fmt, va_list args)
	{
		if (m_LogLevel > level) // If we have the logger's log level set higher than the current level, ignore the message.
			return;

		SetConsoleColor(m_Bindings[static_cast<int>(level)].color);
		std::cout << "[" << m_Bindings[static_cast<int>(level)].identifier << "] ";
		std::vprintf(fmt, args);
		std::cout << std::endl;
		ResetConsoleColor();
	}

private:
#if defined(LOGTOOLS_LINUX)
	// Linux specific
	static void SetConsoleColor(const std::string& color)
	{
		std::cout << color;
	}
	static void ResetConsoleColor()
	{
		std::cout << RESET;
	}
	static void LogColor(const std::string& msg, const std::string& color)
	{
		SetConsoleColor(color);
		std::cout << msg << std::endl;
		ResetConsoleColor();
	}
#elif defined(LOGTOOLS_WINDOWS)
	// Windows specific
	static void SetConsoleColor(const WORD color)
	{
		SetConsoleTextAttribute(Instance().hConsole, color);
	}
	static void ResetConsoleColor()
	{
		SetConsoleTextAttribute(Instance().hConsole, RESET);
	}
	static void LogColor(const std::string& msg, const WORD color)
	{
		SetConsoleColor(color);
		std::cout << msg << std::endl;
		ResetConsoleColor();
	}
#endif

	static Logger Instance()
	{
		static Logger instance{};
		return instance;
	}

private:
#if defined(LOGTOOLS_WINDOWS)
	inline static HANDLE hConsole;
#endif

	inline const static LogBinding m_Bindings[] = {
		{ "TRACE", RESET },
		{ "DEBUG", CYAN },
		{ "INFO", WHITE },
		{ "WARNING", YELLOW },
		{ "ERROR", RED }
	};

	inline static LogLevel m_LogLevel = LogLevel::Trace;
};

#endif //INCLUDE_LOGTOOLS_H
