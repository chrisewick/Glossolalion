workspace "Glossolalion"
	location	"Build"
	configurations { "Debug", "Release" }
	filter "system:windows"
		platforms { "x64", "x86" }
		characterset "Unicode"

project "Glossolalion"
	location "Build/Glossolalion"
	kind "WindowedApp"
	language "C++"
	
	files {
		"Source/**.cpp",
		"Source/**.h",
		"premake5.lua",
		".gitignore",
	}

	includedirs {
		"Source",
	}