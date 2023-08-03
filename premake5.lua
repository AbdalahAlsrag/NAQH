workspace "NAQH"
    configurations { "Debug", "Dev", "Release" }

    architecture "x64"
    startproject "Sandbox"
    compileas "C++"

    output_dir = "%{cfg.buildcfg}-%{cfg.platform}-%{cfg.system}-%{cfg.architecture}"

    -- //NAQH// --
    project "NAQH"
        location "NAQH"
        kind "StaticLib"
        language "C++"
        floatingpoint "Fast"

        targetdir ("bin/" .. output_dir .. "/%{prj.name}")
        objdir ("bin-int/" .. output_dir .. "/%{prj.name}")

        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.c",
            "%{prj.name}/src/**.hpp",
            "%{prj.name}/src/**.cpp",
        }

        includedirs {
            "%{prj.name}/src",
            "%{prj.name}/external/%{cfg.system}"
        }

        links {
            "opengl32",
            "NAQH/external/%{cfg.system}/glfw/glfw3",
            "NAQH/external/%{cfg.system}/glad/glad",
            "NAQH/external/%{cfg.system}/imgui/imgui",
            "NAQH/external/%{cfg.system}/lua/lua",
            "NAQH/external/%{cfg.system}/box2d/box2d",
            "NAQH/external/%{cfg.system}/enet/enet",
            "NAQH/external/%{cfg.system}/stb/stb_image",
        }

        ignoredefaultlibraries {
            "MSVCRT",
            "LIBCMT"
        }

        filter "configurations:Debug"
            defines { "NQ_DEBUG" }
            symbols "On"
            
        filter "configurations:Dev"
            defines { "NQ_DEV" }
            optimize "On"
            symbols "On"

        filter "configurations:Release"
            defines { "NQ_RELEASE" }
            optimize "Full"

    -- //Sandbox// --
    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. output_dir .. "/%{prj.name}")
        objdir ("bin-int/" .. output_dir .. "/%{prj.name}")

        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.c",
            "%{prj.name}/src/**.hpp",
            "%{prj.name}/src/**.cpp",
        }

        includedirs {
            "NAQH/src",
            "%{prj.name}/src",
            "%{prj.name}/external/%{cfg.system}"
        }

        links {
            "NAQH"
        }

        filter "system:windows"
            systemversion "latest"

        filter "configurations:Debug"
            defines { "NQ_DEBUG" }
            symbols "On"
            
        filter "configurations:Dev"
            defines { "NQ_DEV" }
            optimize "On"
            symbols "On"

        filter "configurations:Release"
            defines { "NQ_RELEASE" }
            optimize "Full"