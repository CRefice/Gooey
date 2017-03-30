add_executable(ControlsExample WIN32 Controls.cpp)
target_link_libraries(ControlsExample Gooey)

if(WIN32)
	set_target_properties(ControlsExample PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

set(GOOEY_EXAMPLES ControlsExample)

install(TARGETS ${GOOEY_EXAMPLES} RUNTIME DESTINATION "Bin/Examples")
