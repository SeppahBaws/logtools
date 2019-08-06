#include <iostream>

#include "logtools.h"

int main()
{
    Logger::LogInfo("Hello info");
    Logger::LogWarning("This is a warning");
    Logger::LogError("Failed to do something important!");
}
