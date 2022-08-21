#设置最低版本许可
cmake_minimum_required(VERSION 2.8.7)

#定义项目名称：King
#自动生成两个变量：King_BINARY_DIR 和 demo_SOURCE_DIR
#同时，cmake 自动定义了两个等价的变量 PROJECT_BINARY_DIR 和 PROJECT_SOURCE_DIR
project(smart_home)

#将编译方式设置为Release
#该模式对应的模式为debug
#后者是调试模式，系统运行会慢很多
#所以要求有比较高效的运行方式，建议选择Release
IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF()

#设置可执行文件导出目录
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#设置库文件导出目录
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#设置头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

#设置源文件路径，自动搜索源文件
aux_source_directory(./src SRC_DIR)
#添加需要编译的源文件目录
add_executable(${PROJECT_NAME} ${SRC_DIR})

#生成动态库文件,libxx.so
#add_library(xx SHAREN xx.cpp)

# 安装
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)  # 需要install目录先行存在

INSTALL(TARGETS ${PROJECT_NAME}
RUNTIME DESTINATION lib/${PROJECT_NAME}
)

INSTALL(DIRECTORY ${PROJECT_SOURCE_DIR}/include
DESTINATION share/${PROJECT_NAME}
)