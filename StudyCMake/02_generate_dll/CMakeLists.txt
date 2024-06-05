cmake_minimum_required(VERSION 3.0)
project(dll)

file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD_17)

#指定生成库的路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#库的名字 动态库在windows中叫dll，在liunx中叫so
#        静态库在windows中叫lib，在liunx中叫a

add_library(calc SHARED ${SRC_LIST}) # 动态库
# add_library(calc STATIC ${SRC_LIST}) # 静态库
