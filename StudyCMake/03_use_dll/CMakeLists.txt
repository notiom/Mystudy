cmake_minimum_required(VERSION 3.0)
project(usedll)

file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD_17)

#指定生成可执行文件的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#若库为系统库，则只需要指定名字，若库为自己的库，则需要给定完整路径
#静态库链接命令
# link_libraries(calc)
#指定静态库路径,静态库在应用程序启动时就被加载，而动态库不会被加载，函数调用时才会被加载
# link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libstatic)

#message
message("xxxxxxxxxxxxxxxx")
#动态库目录也是这样指定
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libshared)
#生成可执行文件

add_executable(app ${SRC_LIST})
message(STATUS "11111111xxxxxxxxxxxx")

#动态库链接命令
#动态库链接具有传递性，A 链接 B C D链接 A D也可以使用B C,需要写到文件的最后
target_link_libraries(app calc)
message(STATUS "22222222xxxxxxxxxxxx")

