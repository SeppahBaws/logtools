#include "logtools.h"

int main()
{
	Logger::Init(); // Very important!

	// Normal log functions
	Logger::LogTrace("Some kind of trace message here...");
	Logger::LogDebug("This is a debug message!");
	Logger::LogInfo("Hello info");
	Logger::LogWarning("This is a warning");
	Logger::LogError("Failed to do something important!");

	// Format log functions
	Logger::LogTrace("Hello %x %X", 123, 456);
	Logger::LogDebug("Debug with %s", "argument");
	Logger::LogInfo("Hello %d", 1);
	Logger::LogWarning("Hello %s", "abc");
	Logger::LogError("Hello %.2f", 1.2345f);
}
