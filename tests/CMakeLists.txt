if(BUILD_TESTING)
    include_directories(${CMAKE_SOURCE_DIR}/include/)
    link_directories(${CMAKE_SOURCE_DIR}/lib/)

    add_executable(test1 buf_test.cpp)
    target_link_libraries(
        test1 

		${CMAKE_SOURCE_DIR}/lib/gtest/libgtest_main.a
		${CMAKE_SOURCE_DIR}/lib/gtest/libgtest.a
    )

    add_test(NAME buf_test COMMAND test1)
endif()
