cmake_minimum_required(VERSION 3.5)

add_definitions("-std=c++11")

add_executable(example testLogger.cpp )
add_executable(demo demo.cpp )
target_link_libraries(example Logger)
target_link_libraries(demo Logger)


