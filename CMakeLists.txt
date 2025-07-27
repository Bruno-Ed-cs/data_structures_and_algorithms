cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

project(data_structures)

set(FILES)
file(GLOB_RECURSE FILES "src/*/*.cpp")

add_executable(Linked_lists src/linked.cpp ${FILES})

