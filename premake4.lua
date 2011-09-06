solution "Lithium"
	configurations { "Debug", "Release" }
	includedirs
	{
		"./",
		"$(BASISPATH)",
		"$(RTLPATH)",
		"Libs/Common/Src"
	}
	
	configuration "Debug"
		targetdir "SDK/Debug"
		defines { "DEBUG" }
		flags { "Symbols" }
		libdirs
		{
			"$(RTLPATH)/build/debug"
		}

	configuration "Release"
		targetdir "SDK/Release"
		defines { "NDEBUG" }
		flags { "Optimize" }
		libdirs
		{
			"$(RTLPATH)/build/release"
		}	

	-- Core project
	project "Lithium.Core"
		language "C++"
		kind "StaticLib"
		location "Libs/Core/Build"
		files 
		{
			-- Header Files
			"Lithium/LithiumCore.hpp",
			"Lithium/LithiumCoreLIB.hpp",
			"Lithium/ObjectSystem/*.hpp",
			"Lithium/Mathematics/*.hpp",
			"Lithium/System/*.hpp",

			-- Source Files
			"Libs/Common/Src/*.hpp",
			"Libs/Core/Src/*.cpp",
			"Libs/Core/Src/*.hpp",
			"Libs/Core/Src/Windows/*.cpp"
		}

	-- Graphics project
	project "Lithium.Graphics"
		language "C++"
		kind "StaticLib"
		location "Libs/Graphics/Build"
		files
		{
			-- Header files
			"Lithium/LithiumGraphics.hpp",
			"Lithium/LithiumGraphicsLIB.hpp",
			"Lithium/Graphics/*.hpp",

			-- Source Files
			"Libs/Graphics/Src/*.cpp",
			"Libs/Graphics/Src/*.hpp",
			"Libs/Graphics/Src/*.c",
			"Libs/Graphics/Src/*.h"
		}
		links
		{
			"Lithium.Core"
		}

	-- Network project
	project "Lithium.Network"
		language "C++"
		kind "StaticLib"
		location "Libs/Network/Build"
		files
		{
			-- Header files
			"Lithium/LithiumNetwork.hpp",
			"Lithium/LithiumNetworkLIB.hpp",
			"Lithium/Network/*.hpp",
			"Lithium/Web/*.hpp",

			-- Source Files
			"Libs/Network/Src/*.cpp",
			"Libs/Network/Src/*.hpp",
			"Libs/Network/Src/Windows/*.cpp"
		}
		links
		{
			"Lithium.Network"
		}

	-- Content project
	project "Lithium.Content"
		language "C++"
		kind "StaticLib"
		location "Libs/Content/Build"
		files
		{
			-- Header files
			"Lithium/LithiumContent.hpp",
			"Lithium/LithiumContentLIB.hpp",
			"Lithium/Content/*.hpp",

			-- Source files
			"Libs/Content/Src/*.cpp",
			"Libs/Content/Src/*.hpp"
		}
		links
		{
			"Lithium.Graphics"
		}

	-- Http project
	project "Lithium.HttpServer"
		language "C++"
		kind "StaticLib"
		location "Libs/HttpServer/Build"
		files
		{
			-- Header files
			"Lithium/Web/HttpServer.hpp",

			-- Source files
			"Libs/HttpServer/Src/*.cpp",
			"Libs/HttpServer/Src/*.inl",
			"Libs/HttpServer/Src/json/*.h"
		}


	-- OpenGL 3.x device project
	project "Lithium.OpenGL3Device"
		language "C++"
		kind "StaticLib"
		location "Libs/OpenGL3Device/Build"
		files
		{
			-- Header files
			"Lithium/Graphics/GraphicsDevice.hpp",
			
			-- Source files
			"Libs/OpenGL3Device/Src/*.cpp",
			"Libs/OpenGL3Device/Src/*.hpp"
		}
		links
		{
			"Lithium.Graphics"
		}

	-- Application project
	project "Lithium.Application"
		language "C++"
		kind "WindowedApp"
		location "Libs/Application/Build"
		files
		{
			-- Header Files
			"Lithium/LithiumApplication.hpp",
			"Lithium/LithiumApplicationLIB.hpp",
			"Lithium/Application/*.hpp",
			"Lithium/Input/*.hpp",

			-- Source Files
			"Libs/Application/Src/*.cpp",
			"Libs/Application/Src/*.hpp",
			"Libs/Application/Src/Windows/*.cpp"
		}
		links
		{
			"OpenGL32",
			"XInput",
			"wsock32",
			"ws2_32",
			"rtl.reflection",
			"Lithium.Core",
			"Lithium.Graphics",
			"Lithium.Network",
			"Lithium.OpenGL3Device",
			"Lithium.HttpServer",
			"Lithium.Content"
		}

--[[
	-- Example project
	project "Test.Application"
		language "C++"
		kind "WindowedApp"
		location "Examples/Test/Build"
		files
		{
			-- Source Files
			"Examples/Test/Src/*.cpp",
			"Examples/Test/Src/*.hpp"
		}
		links
		{
			"Lithium.Core",
			--"Lithium.Graphics",
			"Lithium.Application"
		}
]]--
