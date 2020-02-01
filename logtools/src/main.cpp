#include "logtools.h"

int main()
{
	Logger::Init(); // Very important!

	Logger::LogInfo("Hello info");
	Logger::LogWarning("This is a warning");
	Logger::LogError("Failed to do something important!");
}
