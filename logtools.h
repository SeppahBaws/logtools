#pragma once

#if defined(__linux__)

#include "logger_linux.h"

#elif defined(_WIN32)

#include "logger_win.h"

#endif