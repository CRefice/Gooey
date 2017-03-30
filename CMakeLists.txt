cmake_minimum_required(VERSION 3.5)
project(Gooey)

option(GOOEY_BUILD_EXAMPLES "Build and install all examples" OFF)

include_directories(Include)

add_subdirectory(Source)

if(GOOEY_BUILD_EXAMPLES)
	add_subdirectory(Examples)
endif()

file(GLOB Includes "Include/*.hpp")
install(FILES ${Includes} DESTINATION Include)
