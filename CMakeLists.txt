cmake_minimum_required(VERSION 3.17)
project(01)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra" )

add_executable(list List/main.cpp List/Sfinae.hpp)
add_executable(stack Stack/main.cpp Stack/stack.hpp)
add_executable(vector vector/main.cpp Vector/vector.hpp)
add_executable(Test Test/main.cpp)