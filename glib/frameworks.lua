function SetupSolution(slnName)
	solution(slnName)
		configurations {"Debug", "Release"}
end

function SetupProject(projName, ...)
	project(projName)
		kind "ConsoleApp"
		language "c"
		
		files {...}

		includedirs {"/usr/include/glib-2.0/", "/usr/lib/glib-2.0/include/"}
		links "glib-2.0"

		configuration "Debug"
			defines {"DEBUG", "_DEBUG"}
			flags "Symbols"
			targetname(projName .. "D")
		
		configuration "Release"
			defines {"RELEASE", "NDEBUG"};
			flags "OptimizeSpeed";
			targetname(projName)

end

