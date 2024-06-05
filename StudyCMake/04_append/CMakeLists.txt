cmake_minimum_required(VERSION 3.0)
project(hello)

file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

message("----------------------")
#删除子字符串
list(REMOVE_ITEM SRC_LIST ${PROJECT_SOURCE_DIR}/src/main.cpp)

#指定头文件所在的位置
include_directories(${PROJECT_SOURCE_DIR}/include)

#设置c++编译的标准
set(CMAKE_CXX_STANDARD_17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin) # 设置输出路径
add_executable(app ${SRC_LIST}) 

#set拼接字符串
set(tmp hello world)
set(tmp1 ${tmp} ${SRC_LIST})
message(${tmp1})

# 字符串拼接cmake底层会自动加上分号
list(APPEND tmp "xxx1" "sss2" ${SRC_LIST})
message(${tmp})