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
SetupProject("ch01_test1", "ch01/ch01_test1.cpp")
SetupProject("ch01_test2", "ch01/ch01_test2.cpp")
SetupProject("ch01_test3", "ch01/ch01_test3.cpp")

--chaper 02---------
--[[
project "ch02_test"
basedir "ch02"
location "build/ch02"
kind "ConsoleApp"
language "C++"
files {"ch02/*.cpp"}

configuration "Debug"
defines { "DEBUG" }
flags { "Symbols" }

configuration "Release"
defines { "NDEBUG" }
flags { "Optimize" }
--]]
