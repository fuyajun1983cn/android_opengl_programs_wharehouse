# try to find cpluff.h

set(HEADER_SEARCH_PATHS "/usr/local/include" "/usr/include")

find_path(
	CP_INCLUDE_DIRS cpluff.h
	PATHS ${HEADER_SEARCH_PATHS}
	NO_DEFAULT_PATH
)
if(NOT EXISTS ${DFB_INCLUDE_DIRS})
	find_path(DFB_INCLUDE_DIRS cpluff.h)
endif()

# try to find the CP library
find_library(
	CP_LIBRARIES NAMES cpluff
	PATHS ${LIBRARY_SEARCH_PATHS}
	NO_DEFAULT_PATH
)
if(NOT CP_LIBRARIES)
	find_library(CP_LIBRARIES cpluff)
endif()

if(EXISTS ${CP_INCLUDE_DIRS})
	set(CP_FOUND true)
else()
	set(CP_FOUND false)
endif()