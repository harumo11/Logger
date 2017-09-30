cmake_minimum_required(VERSION 3.5)

add_definitions("-std=c++11")

add_executable(example testLogger.cpp )
target_link_libraries(example Logger)


