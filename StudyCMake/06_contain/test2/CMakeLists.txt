cmake_minimum_required(VERSION 3.15)
project(test2)

aux_source_directory(./ SRC_LIST)
include_directories(${HEADPATH})
link_directories(${LIBPATH})
link_libraries(${SORTLIB})

set(CMAKE_CXX_STANDARD_17)

set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})

add_executable(${APPNAME2} ${SRC_LIST})