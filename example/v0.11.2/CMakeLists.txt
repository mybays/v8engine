cmake_minimum_required(VERSION 3.5)
project(v0.11.2)

INCLUDE_DIRECTORIES("/Users/mybays/develop/nodejs/nodelib/v0.11.2/include")
link_directories("/Users/mybays/develop/nodejs/nodelib/v0.11.2/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 1.cpp)
add_executable(1 ${SOURCE_FILES})
target_link_libraries (1 LINK_PUBLIC v8_base.x64 v8_snapshot)

add_executable(2 2.cpp)
target_link_libraries (2 LINK_PUBLIC v8_base.x64 v8_snapshot)

add_executable(heaptest heaptest.cc)
target_link_libraries (heaptest LINK_PUBLIC v8_base.x64 v8_snapshot)

add_executable(process process.cc)
target_link_libraries (process LINK_PUBLIC v8_base.x64 v8_snapshot)

add_executable(shell shell.cc)
target_link_libraries (shell LINK_PUBLIC v8_base.x64 v8_snapshot)

add_executable(version version.cpp)
target_link_libraries (version LINK_PUBLIC v8_base.x64 v8_snapshot)
