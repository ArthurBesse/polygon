cmake_minimum_required(VERSION 3.30)
project(polygon)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(checkers)
add_subdirectory(generators)
add_subdirectory(solutions)
add_subdirectory(validators)


