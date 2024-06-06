cmake_minimum_required(VERSION 3.0)
project(mymacro)
add_definitions(-DDEBUG) #-D宏名称

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(app ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)