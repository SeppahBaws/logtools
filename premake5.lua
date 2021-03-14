workspace "logtools"
    architecture "x86_64"

    configurations
    {
        "Debug",
        "Release"
    }

    startproject "logtools"

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}"

project "logtools"
    location "logtools"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    warnings "extra"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir)

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    flags
    {
        "FatalWarnings"
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
