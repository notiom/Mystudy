cmake_minimum_required(VERSION 3.15)
project(sort)

#搜索源文件
aux_source_directory(./ SRC_LIST)
include_directories(${HEADPATH})
set(LIBRARY_OUTPUT_PATH ${LIBPATH})

#链接静态库-------------
link_directories(${LIBPATH})
link_libraries(${CALCLIB})

#添加库
add_library(${SORTLIB} STATIC ${SRC_LIST})