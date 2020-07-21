#include "logtools.h"

int main()
{
	Logger::Init(); // Very important!

	Logger::LogInfo("Hello info");
	Logger::LogWarning("This is a warning");
	Logger::LogError("Failed to do something important!");
	Logger::Log(LogLevel::Info, "Greetings!");

	Logger::LogInfo("Hello %d", 1);
	Logger::LogWarning("Hello %s", "abc");
	Logger::LogError("Hello %.2f", 1.2345f);
}
