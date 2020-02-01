#pragma once

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
