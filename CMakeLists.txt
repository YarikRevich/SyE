if (NOT WIN32)
	cmake_minimum_required(VERSION 3.16)
	project(editor VERSION 0.0.1 LANGUAGES C CXX)
	# include(CTest)

	set(CMAKE_CXX_COMPILER /usr/bin/g++)
	set(CMAKE_CXX_FLAGS "-std=c++17 -D_XOPEN_SOURCE_EXTENDED -DBOOST_NO_CXX11_SCOPED_ENUMS")
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
	message("Make build output path is /bin")

	# Describes configuration structure properties.
	add_compile_definitions(CONFIG_ROOT_PATH="~/.sye")
	add_compile_definitions(CONFIG_FILE_NAME="config.yaml")
	add_compile_definitions(THEME_CONFIG_PATH="themes")

	# Describes pre-defined errors used for functionality validation.
	add_compile_definitions(CONFIG_FILE_NOT_FOUND_EXCEPTION="Configuration file at the given root directory is not found.")
	add_compile_definitions(THEME_DIRECTORY_NOT_FOUND_EXCEPTION="Theme configuration files at the given root directory are not found.")

	# Describes pre-defined warning messages used for functionality validation.
	add_compile_definitions(CONFIG_FILE_IDENTATION_WARNING="Make sure to use spaces in your configuration file.")
	add_compile_definitions(DEFAULT_THEME_USAGE_WARNING="Default theme is used.")

	# Describes pre-defined info messages used for functionality validation.
	add_compile_definitions(CUSTOM_THEME_SELECTED="Custom theme has been selected.")

	# Describes keys used for configuration file properties.
	add_compile_definitions(CONFIG_WIDGETS_KEY="widgets")

	# Describes keys used for theme configuration file properties.
	add_compile_definitions(THEME_CONFIG_EXTENSIONS_KEY="extensions")
	add_compile_definitions(THEME_CONFIG_COLORS_KEY="colors")
	add_compile_definitions(THEME_CONFIG_COLORS_NAME_KEY="name")
	add_compile_definitions(THEME_CONFIG_COLORS_VALUE_KEY="value")
	add_compile_definitions(THEME_CONFIG_EFFECTS_KEY="effects")
	add_compile_definitions(THEME_CONFIG_EFFECTS_BACKGROUND_KEY="background")
	add_compile_definitions(THEME_CONFIG_PATTERNS_KEY="patterns")
	add_compile_definitions(THEME_CONFIG_PATTERNS_REGEX_KEY="regex")
	add_compile_definitions(THEME_CONFIG_PATTERNS_COLOR_KEY="color")

	# Describes definitions of variable in exceptional cases.
	add_compile_definitions(THEME_EXTENSION_NONE=" ")

	# enable_testing()
	# add_subdirectory(tests)

	include_directories(
		"include/"
	)
	link_directories(
		"lib/"
	)

	add_executable(
		sye 

		src/cmd/main.cpp

		src/internal/command/handler/handler.cpp
		src/internal/command/help/help.cpp
		src/internal/command/validator/validator.cpp
		src/internal/command/entry/entry.cpp

		src/internal/io/helper/helper.cpp
		src/internal/io/loader/config/config.cpp
		src/internal/io/loader/config/validator/validator.cpp
		src/internal/io/loader/theme/theme.cpp
		src/internal/io/loader/theme/validator/validator.cpp

		src/internal/signal/signal.cpp
		src/internal/logger/logger.cpp
		src/internal/tools/tools.cpp
	)

	if(APPLE)
		if (${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "arm64")
			target_link_libraries(
				sye 

				${CMAKE_SOURCE_DIR}/lib/ncursesw/macos/arm/libncursesw.a
				${CMAKE_SOURCE_DIR}/lib/yaml-cpp/macos/arm/libyaml-cpp.a
				${CMAKE_SOURCE_DIR}/lib/gtest/macos/arm/libgtest_main.a
				${CMAKE_SOURCE_DIR}/lib/gtest/macos/arm/libgtest.a
				${CMAKE_SOURCE_DIR}/lib/boost/macos/arm/libboost_filesystem.a
				${CMAKE_SOURCE_DIR}/lib/boost/macos/arm/libboost_system.a
			)
		else()
			target_link_libraries(
				sye 

				${CMAKE_SOURCE_DIR}/lib/ncursesw/macos/x86/libncursesw.a
				${CMAKE_SOURCE_DIR}/lib/yaml-cpp/macos/x86/libyaml-cpp.a
				${CMAKE_SOURCE_DIR}/lib/gtest/macos/x86/libgtest_main.a
				${CMAKE_SOURCE_DIR}/lib/gtest/macos/x86/libgtest.a
				${CMAKE_SOURCE_DIR}/lib/boost/macos/x86/libboost_filesystem.a
				${CMAKE_SOURCE_DIR}/lib/boost/macos/x86/libboost_system.a
			)
		endif()
	elseif(UNIX)
		target_link_libraries(
			sye 
			stdc++fs

			${CMAKE_SOURCE_DIR}/lib/yaml-cpp/linux/libyaml-cpp.0.6.3.so
			${CMAKE_SOURCE_DIR}/lib/gtest/linux/libgtest_main.a
			${CMAKE_SOURCE_DIR}/lib/gtest/linux/libgtest.a
			${CMAKE_SOURCE_DIR}/lib/boost/linux/libboost_filesystem.a
			${CMAKE_SOURCE_DIR}/lib/boost/linux/libboost_system.a
		)
	endif()

	install(TARGETS sye DESTINATION /usr/local/bin)
else()
	message("Windows is not supported")
endif()
