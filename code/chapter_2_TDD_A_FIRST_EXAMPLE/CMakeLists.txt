project(chapter_2)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/my_build $ENV{GMOCK_HOME}/gtest/my_build)
add_definitions(-std=c++1y)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(sources
        main.cpp
        SoundexTest.cpp
        Soundex.hpp
   )
add_executable(test_application ${sources})
target_link_libraries(test_application pthread)
target_link_libraries(test_application gmock)
target_link_libraries(test_application gtest)
