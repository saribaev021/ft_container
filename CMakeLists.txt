cmake_minimum_required(VERSION 3.17)
project(01)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra" )

add_executable(list List/main.cpp)
add_executable(stack Stack/main.cpp Stack/stack.hpp)
add_executable(vector Vector/main.cpp)
add_executable(map Map/main.cpp)
add_executable(Test Test/main.cpp)

add_executable(hello Vector/main.cpp)
