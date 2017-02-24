add_executable(ControlTest WIN32 ControlTest.cpp)
target_link_libraries(ControlTest Gooey)

if(WIN32)
	set_target_properties(ControlTest PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

set(GOOEY_TESTS ControlTest)

install(TARGETS ${GOOEY_TESTS} RUNTIME DESTINATION "Bin/Tests")
