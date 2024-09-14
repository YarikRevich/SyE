if (WIN32)
	message(FATAL_ERROR "Windows is not supported")
endif()

cmake_minimum_required(VERSION 3.16)
project(editor VERSION 0.0.1 LANGUAGES C CXX)
# include(CTest)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_FLAGS "-std=c++17 -D_XOPEN_SOURCE_EXTENDED -DBOOST_NO_CXX11_SCOPED_ENUMS")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message("Make build output path is /bin")

# Describes input file properties.
add_compile_definitions(DEFAULT_INPUT_FILE_HASH="0")

# Describes configuration structure properties.
add_compile_definitions(CONFIG_ROOT_PATH="~/.sye")
add_compile_definitions(CONFIG_FILE_PATH="config")
add_compile_definitions(CONFIG_FILE_NAME="config.yaml")
add_compile_definitions(THEME_CONFIG_PATH="themes")
add_compile_definitions(SWAP_FILES_PATH="swap")

# Describes pre-defined errors used for functionality validation.
add_compile_definitions(
		CONFIG_FILE_NOT_FOUND_EXCEPTION="Configuration file at the given root directory is not found.")
add_compile_definitions(
		CONFIG_FILE_WIDGET_NOT_SUPPORTED_EXCEPTION="Widget in the configuration file seems to be not supported.")
add_compile_definitions(
		THEME_DIRECTORY_NOT_FOUND_EXCEPTION="Theme configuration files at the given root directory are not found.")
add_compile_definitions(
		THEME_FILE_EXTENSIONS_REPEAT_EXCEPTION="Extensions in the theme configuration file seem to be repeated.")
add_compile_definitions(
		THEME_FILE_COLORS_DEFINED_INCORRECTLY_EXCEPTION="Colors in the theme configuration file seem to be defined incorrectly.")
add_compile_definitions(
		THEME_FILE_EFFECTS_USE_INCORRECT_COLORS_EXCEPTION="Effects in the theme configuration file seem to use incorrect colors.")
add_compile_definitions(
		THEME_FILE_PATTERNS_USE_INCORRECT_COLORS_EXCEPTION="Patterns in the theme configuration file seem to use incorrect colors.")

# Describes pre-defined warning messages used for functionality validation.
add_compile_definitions(CONFIG_FILE_INDENTATION_WARNING="Make sure to use spaces in your configuration file.")
add_compile_definitions(CONFIG_FILE_WIDGETS_REPEAT_EXCEPTION="Widgets in the configuration file seem to be repeated.")
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
add_compile_definitions(THEME_CONFIG_EFFECTS_FONT_KEY="font")
add_compile_definitions(THEME_CONFIG_PATTERNS_KEY="patterns")
add_compile_definitions(THEME_CONFIG_PATTERNS_REGEX_KEY="regex")
add_compile_definitions(THEME_CONFIG_PATTERNS_COLOR_KEY="color")

# Describes definitions of variable in exceptional cases.
add_compile_definitions(THEME_EXTENSION_NONE=" ")

# Describes definitions of events managements.
add_compile_definitions(EVENT_BATCH_SIZE=1)

# Describes definitions of all the supported widgets.
add_compile_definitions(WIDGET_TIME="time")
add_compile_definitions(WIDGETS_NUM=1)

# Describes definitions of all the used color themes.
add_compile_definitions(BACKGROUND_COLOR=1)
add_compile_definitions(FONT_COLOR=2)
add_compile_definitions(SELECTED_THEME=1)

# Describes definitions of different scheduler types.
add_compile_definitions(SCHEDULER_PRIORITY_1=5)
add_compile_definitions(SCHEDULER_PRIORITY_2=20)
add_compile_definitions(SCHEDULER_PRIORITY_3=1000)
add_compile_definitions(SCHEDULER_PRIORITY_4=1500)
add_compile_definitions(SCHEDULER_PRIORITY_5=5000)

# Describes definitions of keymaps.
add_compile_definitions(ENTER_KEY=10)
add_compile_definitions(BACKSPACE_KEY=127)
add_compile_definitions(COMMAND_KEY=58)
add_compile_definitions(MOVE_UP_KEY=72)
add_compile_definitions(MOVE_DOWN_KEY=80)
add_compile_definitions(MOVE_LEFT_KEY=75)
add_compile_definitions(MOVE_RIGHT_KEY=77)

# Describes definitions of available commands.
add_compile_definitions(UNDO_COMMAND=117)
add_compile_definitions(SEARCH_COMMAND=115)
add_compile_definitions(INSERT_COMMAND=105)

# Describes application tests configuration.
enable_testing()
add_subdirectory(tests)

include_directories(
	"include/"
)

link_directories(
	"lib/"
)

add_executable(
	sye 
	src/cmd/main.cpp
	src/internal/state/common/common.cpp
	src/internal/state/global/global.cpp
	src/internal/state/entry/entry.cpp
	src/internal/state/event/event.cpp
	src/internal/state/window/window.cpp
	src/internal/state/input/input.cpp
	src/internal/state/widget/time/time.cpp
	src/internal/state/widget/widget.cpp
	src/internal/state/swap/swap.cpp
	src/internal/state/state.cpp
	src/internal/command/handler/handler.cpp
	src/internal/command/help/help.cpp
	src/internal/command/validator/validator.cpp
	src/internal/command/entry/entry.cpp
	src/internal/core/effects/effects.cpp
	src/internal/core/effects/window/window.cpp
	src/internal/core/effects/swap/swap.cpp
	src/internal/core/effects/input/input.cpp
	src/internal/core/effects/content/content.cpp
	src/internal/core/effects/loader/loader.cpp
	src/internal/io/helper/helper.cpp
    src/internal/core/scheduler/input/input.cpp
	src/internal/core/scheduler/input/common/common.cpp
	src/internal/core/scheduler/input/mode/command/command.cpp
	src/internal/core/scheduler/input/mode/insert/insert.cpp
	src/internal/core/scheduler/input/mode/view/view.cpp
	src/internal/core/scheduler/scheduler.cpp
	src/internal/core/scheduler/cleaner/cleaner.cpp
    src/internal/core/scheduler/render/render.cpp
	src/internal/core/scheduler/event/event.cpp
	src/internal/core/scheduler/swap/swap.cpp
	src/internal/core/scheduler/widget/time/time.cpp
	src/internal/core/scheduler/widget/widget.cpp
	src/internal/io/swap/swap.cpp
	src/internal/io/config/helper/helper.cpp
	src/internal/io/config/loader/loader.cpp
	src/internal/io/theme/helper/helper.cpp
	src/internal/io/theme/loader/loader.cpp
    src/internal/core/signal/signal.cpp
	src/internal/logger/logger.cpp
	src/internal/tools/spinner/spinner.cpp
	src/internal/tools/window/window.cpp
)

if(APPLE)
	if (${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "arm64")
		target_link_libraries(
			sye 
			${CMAKE_SOURCE_DIR}/lib/ncursesw/macos/arm/libncursesw.a
			${CMAKE_SOURCE_DIR}/lib/yaml-cpp/macos/arm/libyaml-cpp.a
			${CMAKE_SOURCE_DIR}/lib/openssl/macos/arm/libssl.a
			${CMAKE_SOURCE_DIR}/lib/openssl/macos/arm/libcrypto.a
			${CMAKE_SOURCE_DIR}/lib/jsoncpp/macos/arm/libjsoncpp.a
			${CMAKE_SOURCE_DIR}/lib/gtest/macos/arm/libgtest_main.a
			${CMAKE_SOURCE_DIR}/lib/gtest/macos/arm/libgtest.a
			${CMAKE_SOURCE_DIR}/lib/boost/macos/arm/libboost_iostreams.a
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