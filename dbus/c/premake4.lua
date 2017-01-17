--Helper function
function SetupProject(projName, ...)
	project(projName)
		kind "ConsoleApp"
		language "c"
		
		files {...}

   		includedirs {"/usr/include/dbus-1.0/", "/usr/lib/dbus-1.0/include"}
   		links "dbus-1"

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
SetupProject("dbus-example", "dbus-example.c")

