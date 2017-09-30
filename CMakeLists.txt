cmake_minimum_required(VERSION 3.5)

project(Logger)

add_definitions("-std=c++11")

set(SRC_DIR src)
set(INCLUDE_DIR include/Logger)

include_directories(${INCLUDE_DIR})

add_library(Logger STATIC
	${SRC_DIR}/Logger.cpp
	${SRC_DIR}/Progress.cpp
	)

install(TARGETS Logger
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	)

install(DIRECTORY include/Logger
	DESTINATION /usr/local/include
	)

#add_executable(testLogger example/testLogger Logger.cpp Progress.cpp)

