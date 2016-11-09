cmake_minimum_required(VERSION 3.5)
project(v0.11.2)

INCLUDE_DIRECTORIES("/Users/mybays/develop/nodejs/nodelib/v4.5.0")
link_directories("/Users/mybays/develop/nodejs/nodelib/v4.5.0/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES hello-world.cc /Users/mybays/develop/nodejs/nodelib/v4.5.0/lib/sys-info.o)
add_executable(hello-world ${SOURCE_FILES})
target_link_libraries(hello-world dl pthread)
target_link_libraries(hello-world libv8_base.a libv8_snapshot.a libv8_libbase.a libv8_libplatform.a)




set(CMAKE_EXE_LINKER_FLAGS -mmacosx-version-min=10.5)

