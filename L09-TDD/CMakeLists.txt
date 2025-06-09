cmake_minimum_required(VERSION 3.6)
project(Clase9TDD)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES
        main.cpp
        # sources
        src/ejemplo.cpp
        # tests
        test/testEjemplo.cpp
)

add_executable(Clase9TDD ${SOURCE_FILES})

target_link_libraries(Clase9TDD gtest gtest_main)
