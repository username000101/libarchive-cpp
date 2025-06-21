cmake_minimum_required(VERSION 3.31)
project(libarchive_cpp)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(third_party/libarchive)

add_library(archive-cpp SHARED
        src/GetFiles.cpp
        src/Extract.cpp
)
target_include_directories(archive-cpp PUBLIC include third_party/libarchive/libarchive)
target_link_libraries(archive-cpp PUBLIC archive)
