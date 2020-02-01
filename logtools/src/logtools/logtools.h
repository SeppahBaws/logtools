#pragma once

#if defined(__linux__)
	#include "logger_linux.h"
#elif defined(_WIN32) || defined(_WIN64)
	#include "logger_win.h"
#endif
