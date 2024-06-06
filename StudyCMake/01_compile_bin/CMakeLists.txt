cmake_minimum_required(VERSION 3.15)
project(hello)
# 添加方式一，鸡肋
# add_executable(app add.cpp div.cpp main.cpp mult.cpp sub.cpp)

#set命令
# SET(SRC_LIST add.cpp div.cpp main.cpp mult.cpp sub.cpp)

#搜索文件方式1:aux_source_directory-------------
#获取源文件 ROJECT_SOURCE_DIR是指cmake ..的路径
# aux_source_directory(${PROJECT_SOURCE_DIR} SRC_LIST)

#搜索方式2:file--------------
#CMAKE_CURRENT_SOURCE_DIR} 路径与PROJECT_SOURCE_DIR相同
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#指定头文件所在的位置
include_directories(${PROJECT_SOURCE_DIR}/include)

#设置c++编译的标准
set(CMAKE_CXX_STANDARD 17) # 要跟在cmake .. -DCMAKE_CXX_STANDARD=11

set(EXECUTABLE_OUTPUT_PATH /Users/cds-dn-173/Desktop/xl/code/cpp/StudyCmake/bin) # 设置输出路径
add_executable(app ${SRC_LIST}) # 使用$符格式化