cmake_minimum_required(VERSION 3.14)
project(RasterImageEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(main main.cpp ${SRC_FILES})
