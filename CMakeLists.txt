if(NOT WIN32)
	cmake_minimum_required(VERSION 3.20)
	project(editor VERSION 0.0.1 LANGUAGES C CXX)
	set(CMAKE_CXX_COMPILER /usr/bin/g++)
	set(CMAKE_CXX_FLAGS "-std=gnu++2a")
	set(EXECUTABLE_OUTPUT_PATH, /cmd)
	message("Make build output path is /cmd")

	find_package(yaml-cpp REQUIRED)
	message("Found yaml-cpp lib")
	find_package(Boost COMPONENTS REQUIRED filesystem system)
	message("Found boost lib")
	set(Boost_USE_STATIC_LIBS OFF)
	set(Boost_USE_MULTITHREADED ON)
	set(Boost_USE_STATIC_RUNTIME OFF)


	include_directories(${YAML_CPP_INCLUDE_DIRS})
	include_directories(${Boost_INCLUDE_DIRS})
	add_executable(
		sye 
		cmd/main.cpp
		internal/loop/loop.cpp 
		internal/keys/keys.cpp 

		internal/margin/margin.cpp 

		internal/commands/set_insert_color/set_insert_color.cpp 
		internal/commands/pool.cpp 
		internal/commands/w/w.cpp 
		internal/commands/search/search.cpp 

		internal/bufs/bufs.cpp 

		internal/states/common/common.cpp 
		internal/states/insert/insert.cpp 
		internal/states/pool/pool.cpp 
		internal/states/search/search.cpp 
		internal/states/command/command.cpp 
		internal/status/status.cpp 

		internal/history/history.cpp 
		internal/position/position.cpp 
		internal/term_flags/term_flags.cpp 

		internal/files/helper/helper.cpp 
		internal/files/exec/exec.cpp 
		internal/files/configs/config.cpp 
		internal/files/configs/syntax_config/syntax_config.cpp 
		internal/files/configs/theme_config/theme_config.cpp 
		internal/files/log/log.cpp 

		internal/render/render.cpp 
	
		internal/highlighter/highlighter.cpp 
		internal/colors/command/command.cpp  
		internal/colors/effects/effects.cpp 
		internal/colors/font/font.cpp 
		internal/colors/insert/insert.cpp
		internal/colors/colors.cpp 
	)
	target_link_libraries(sye ${YAML_CPP_LIBRARIES} ${Boost_FILESYSTEM_LIBRARIES} ${Boost_SYSTEM_LIBRARIES})

	if(NOT APPLE)
		target_link_libraries(sye ncurses stdc++fs)
	else()
    	target_link_libraries(sye ncurses)
	endif()
	if (NOT EXISTS $ENV{HOME}/.sye_configs)
		file(MAKE_DIRECTORY $ENV{HOME}/.sye_configs)	
		message("Created directory for configs")
	endif()
	if (NOT EXISTS $ENV{HOME}/.sye_configs/syntax)
		file(MAKE_DIRECTORY $ENV{HOME}/.sye_configs/syntax)
		message("Created directory for syntax configs")
	endif()
	if (NOT EXISTS $ENV{HOME}/.sye_configs/theme)
		file(MAKE_DIRECTORY $ENV{HOME}/.sye_configs/theme)
		message("Created directory for theme configs")
	endif()
	file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/configs/syntax_configs/. DESTINATION $ENV{HOME}/.sye_configs/syntax)
	message("Copied syntax configs to ~/.sye_config/syntax directory")
	file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/configs/theme_configs/. DESTINATION $ENV{HOME}/.sye_configs/theme)
	message("Copied theme configs to ~/.sye_config/theme directory")
	install(TARGETS sye DESTINATION bin)
else()
	message("You mustn't use the worst os in the world to install this perfect editor")
endif()
