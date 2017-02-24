cmake_minimum_required(VERSION 3.5)
project(Gooey)

option(GOOEY_BUILD_TESTS "Build all tests" OFF)

include_directories(Include)

add_subdirectory(Source)

if(GOOEY_BUILD_TESTS)
	add_subdirectory(Tests)
endif()

file(GLOB Includes "Include/*.hpp")
install(FILES ${Includes} DESTINATION Include)
