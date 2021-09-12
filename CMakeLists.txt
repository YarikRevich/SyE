if (NOT WIN32)
	cmake_minimum_required(VERSION 3.16)
	project(editor VERSION 0.0.1 LANGUAGES C CXX)
	include(CTest)

	set(CMAKE_CXX_COMPILER /usr/bin/g++)
	set(CMAKE_CXX_FLAGS "-std=c++2a -D_XOPEN_SOURCE_EXTENDED")
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/cmd)
	message("Make build output path is /cmd")

	enable_testing()
	add_subdirectory(tests)


	if (APPLE)
		include_directories("/usr/local/opt/ncurses/include")
		link_directories("/usr/local/opt/ncurses/lib")
	endif()

	include_directories("include/")
	link_directories("lib/")

	add_executable(
		sye 
		cmd/main.cpp
		internal/loop/loop.cpp
		internal/loop/helper/helper.cpp
		internal/loop/processors/processors.cpp
		internal/loop/initialisers/initialisers.cpp
		
		internal/keys/keys.cpp 

		internal/margin/margin.cpp 

		internal/commands/w/w.cpp 
		internal/commands/z/z.cpp
		internal/commands/helper/helper.cpp
		internal/commands/search/search.cpp 
		internal/commands/applicator/applicator.cpp
		
		internal/bufs/bufs.cpp 

		internal/states/common/common.cpp 
		internal/states/common/helper/helper.cpp
		internal/states/insert/insert.cpp 
		internal/states/search/search.cpp 
		internal/states/command/command.cpp 
		internal/editor_status/editor_status.cpp 

		internal/history/history.cpp 

		internal/position/win_resizer/win_resizer.cpp
		internal/position/position.cpp 


		internal/term_flags/term_flags.cpp 

		internal/files/helper/helper.cpp 
		internal/files/exec/exec.cpp 
		internal/files/configs/helper/helper.cpp 
		internal/files/configs/syntax_config/syntax_config.cpp 
		internal/files/configs/theme_config/theme_config.cpp 
		internal/files/configs/widgets/widgets.cpp 
		internal/files/log/log.cpp 

		internal/render/render.cpp 
	
		internal/highlighter/highlighter.cpp 
		internal/colors/command/command.cpp  
		internal/colors/effects/effects.cpp 
		internal/colors/font/font.cpp 
		internal/colors/insert/insert.cpp
		internal/colors/colors.cpp 

		internal/widgets/time/time.cpp
	)

	target_link_libraries(
		sye 
		ncursesw

		${CMAKE_SOURCE_DIR}/lib/yaml-cpp/libyaml-cpp.0.6.3.dylib
		${CMAKE_SOURCE_DIR}/lib/gtest/libgtest_main.a
		${CMAKE_SOURCE_DIR}/lib/gtest/libgtest.a
		${CMAKE_SOURCE_DIR}/lib/boost/libboost_filesystem.a
		${CMAKE_SOURCE_DIR}/lib/boost/libboost_system.a
	)

	if(NOT APPLE)
		target_link_libraries(sye ncursesw stdc++fs)
	else()
	    target_link_libraries(sye ncursesw)
	endif()
	if (NOT EXISTS /usr/local/etc/sye)
		file(MAKE_DIRECTORY /usr/local/etc/sye)	
		message("Created directory for configs")
	endif()
	if (NOT EXISTS /usr/local/etc/sye/syntax)
		file(MAKE_DIRECTORY /usr/local/etc/sye/syntax)
		message("Created directory for syntax configs")
	endif()
	if (NOT EXISTS /usr/local/etc/sye/theme)
		file(MAKE_DIRECTORY /usr/local/etc/sye/theme)
		message("Created directory for theme configs")
	endif()
	if (NOT EXISTS /usr/local/etc/sye/widgets)
		file(MAKE_DIRECTORY /usr/local/etc/sye/widgets)
		message("Created directory for widgets config")
	endif()
	file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/configs/syntax_configs/. DESTINATION /usr/local/etc/sye/syntax)
	message("Copied syntax configs to /usr/local/etc/sye/syntax directory")
	file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/configs/theme_configs/. DESTINATION /usr/local/etc/sye/theme)
	message("Copied theme configs to /usr/local/etc/sye/theme directory")
	file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/configs/widgets/. DESTINATION /usr/local/etc/sye/widgets)
	message("Copied theme configs to /usr/local/etc/sye/theme directory")

	install(TARGETS sye DESTINATION /usr/local/bin)
else()
	message("You mustn't use the worst os in the world to install this perfect editor")
endif()
