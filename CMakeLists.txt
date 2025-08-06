cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

project(data_structures)

add_executable(Linked_lists src/linked_lists_tests.cpp src/linked_l/ki.cpp)

add_executable(O2_pow_n src/complexidade/O\(2ⁿ\).c)
add_executable(Olog_n src/complexidade/O\(log\ n\).c)
add_executable(O_n src/complexidade/O\(n\).c)
add_executable(On_pow_2 src/complexidade/O\(n²\).c)






