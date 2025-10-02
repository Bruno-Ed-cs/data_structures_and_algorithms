cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

project(data_structures)

# Use pkg-config to find Graphviz
find_package(PkgConfig REQUIRED)
pkg_check_modules(GRAPHVIZ REQUIRED libgvc libcgraph libcdt)

message(STATUS "Graphviz includes: ${GRAPHVIZ_INCLUDE_DIRS}")
message(STATUS "Graphviz libraries: ${GRAPHVIZ_LIBRARIES}")

add_executable(linked_list src/linked_l/linked_lists_tests.cpp)

add_executable(O2_pow_n src/complexidade/O\(2ⁿ\).c)
add_executable(Olog_n src/complexidade/O\(log\ n\).c)
add_executable(O_n src/complexidade/O\(n\).c)
add_executable(On_pow_2 src/complexidade/O\(n²\).c)
add_executable(arvore_simples src/arvores/arvore_simples.c)
add_executable(ordenadores src/ordenacao/testes.cpp)
add_executable(busca src/busca/testes.cpp)
add_executable(grafo src/grafos/atividade.cpp)

# Add include directories and link libraries for the tree executable
target_include_directories(arvore_simples PRIVATE ${GRAPHVIZ_INCLUDE_DIRS})
target_link_libraries(arvore_simples PRIVATE ${GRAPHVIZ_LIBRARIES})
target_link_libraries(grafo PRIVATE ${GRAPHVIZ_LIBRARIES})
