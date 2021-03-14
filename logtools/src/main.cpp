#include "logtools.h"
#include <iostream>

int main()
{
	Logger::Init(true, "output.log", false); // Very important!

	Logger::Configure({ true, true });

	// Normal log functions
	Logger::LogTrace("Some kind of trace message here...");
	Logger::LogDebug("This is a debug message!");
	Logger::LogInfo("Hello info");
	Logger::LogWarning("This is a warning");
	Logger::LogError("Failed to do something important!");

	std::cout << std::endl; // Just for some spacing in the demo

	Logger::Configure({ true, false });

	// Format log functions
	Logger::LogTrace("Hello %x %X", 123, 456);
	Logger::LogDebug("Debug with %s", "argument");
	Logger::LogInfo("Hello %d", 1);
	Logger::LogWarning("Hello %s", "abc");
	Logger::LogError("Hello %.2f", 1.2345f);

	std::cout << std::endl; // Just for some spacing in the demo

	Logger::Configure({ false, true });

	// Setting the log level.
	Logger::SetLevel(LogLevel::Info);
	Logger::LogTrace("This now shouldn't show up");
	Logger::LogDebug("This shouldn't show up either");
	Logger::SetLevel(LogLevel::Trace);
	Logger::LogTrace("Oh hi now I show up!");
	Logger::LogDebug("I show up as well!");
	Logger::LogInfo("This should show up.");
	Logger::LogWarning("This shows up as well");
	Logger::LogError("And this shows too!");

	std::cout << std::endl;

	Logger::Configure({ false, false });

	Logger::LogTrace("Hello World!");
}
