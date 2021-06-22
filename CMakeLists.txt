project(editor)
set(CMAKE_CXX_FLAGS "-std=gnu++2a")
add_executable(main main.cpp init/init.cpp internal/colors/colors.cpp internal/context/context.cpp internal/history/history.cpp internal/position/position.cpp internal/term_flags/term_flags.cpp internal/commands/commands.cpp internal/commands/w/w.cpp internal/files/files.cpp internal/states/states.cpp internal/log/dev/dev.cpp)
target_link_libraries(main ncurses stdc++fs)
