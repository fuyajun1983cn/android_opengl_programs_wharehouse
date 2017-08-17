solution "MyApplication"
configurations { "Debug", "Release" }
location "build"
targetdir "output"

--chapter 01------
project "ch01_test1"
basedir "ch01"
location "build/ch01"
kind "ConsoleApp"
language "C++"
files { "ch01/*.h", "ch01/*.cpp" }

configuration "Debug"
defines { "DEBUG" }
flags { "Symbols" }

configuration "Release"
defines { "NDEBUG" }
flags { "Optimize" }

--chaper 02---------
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
