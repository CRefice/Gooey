if (WIN32)
	file (GLOB_RECURSE Sources "Win/*.cpp")
else ()
	file (GLOB_RECURSE Sources "Gtk/*.cpp")
endif (WIN32)

add_library (Gooey ${Sources})

install(TARGETS Gooey DESTINATION Lib)
