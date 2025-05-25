cmake_minimum_required(VERSION 3.31)
project(libarchive_cpp)

set(CMAKE_CXX_STANDARD 23)

add_library(libarchive-cpp SHARED
        src/GetFiles.cpp
        src/Extract.cpp
)

target_link_libraries(libarchive-cpp PUBLIC libarchive.so)
target_include_directories(libarchive-cpp PUBLIC include)
