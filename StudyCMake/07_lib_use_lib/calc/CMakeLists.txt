cmake_minimum_required(VERSION 3.15)
project(calc)

#搜索源文件
aux_source_directory(./ SRC_LIST)
include_directories(${HEADPATH})
set(LIBRARY_OUTPUT_PATH ${LIBPATH})

#添加库
add_library(${CALCLIB} STATIC ${SRC_LIST})