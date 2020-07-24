# logtools
A small and simple cross-platform logging toolset.

## Features

- Easy logging
- Cross-platform for Windows and Linux

## Get started

Please note: currently the library is made with C++17 in mind, as that is the main C++ version I'm using for my new projects right now.

- Go to the [releases](https://github.com/SeppahBaws/logtools/releases) tab and download the latest version of the library.
It should only be a single file called logtools.h

- Include `logtools.h` in your project

- At the start of your program, call `Logger::Init();` to initialize the logger.

- Then you can use the logging functions that the Logger provides:
	- `LogTrace(msg)` or `LogTrace(format, arguments)`
	- `LogDebug(msg)` or `LogDebug(format, arguments)`
	- `LogInfo(msg)` or `LogInfo(format, arguments)`
	- `LogWarning(msg)` or `LogWarning(format, arguments)`
	- `LogError(msg)` or `LogError(format, arguments)`

For a full demo of what the library can do, please see the [main.cpp (logtools/src/main.cpp)](https://github.com/SeppahBaws/logtools/blob/master/logtools/src/main.cpp) file in the repository.

## Issues

If you have any troubles setting up or using this library, please create an issue [here](https://github.com/SeppahBaws/logtools/issues/new)
