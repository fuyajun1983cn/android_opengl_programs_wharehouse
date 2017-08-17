--Helper function
function SetupProject(projName, ...)
	project(projName)
		kind "ConsoleApp"
		language "c++"
		
		files {...}

                configuration "Debug"
                defines { "DEBUG" }
                flags { "Symbols" }

                configuration "Release"
                defines { "NDEBUG" }
                flags { "Optimize" }
	
end


solution "MyApplication"
configurations { "Debug", "Release" }
location "build"
targetdir "output"

--chapter 01------
SetupProject("lambda1", "lambda1.cpp")

