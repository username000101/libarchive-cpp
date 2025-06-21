cmake_minimum_required(VERSION 3.31)
project(libarchive_cpp)

set(CMAKE_CXX_STANDARD 23)

add_library(archive-cpp SHARED
        src/GetFiles.cpp
        src/Extract.cpp
)


target_include_directories(archive-cpp PUBLIC include)

if (libarchive_library)
    target_link_libraries(archive-cpp PRIVATE ${libarchive_library})
else ()
    message(WARNING "Trying to find the libarchive.so in default paths...")
    target_link_libraries(archive-cpp PRIVATE libarchive.so)
endif ()
