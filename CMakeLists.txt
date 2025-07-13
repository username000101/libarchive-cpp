cmake_minimum_required(VERSION 3.31)
project(libarchive_cpp)

set(CMAKE_CXX_STANDARD 23)
set(BUILD_SHARED_LIBS ON)

add_library(archive-cpp
        src/GetFiles.cpp
        src/Extract.cpp
)
if (NOT DEFINED libarchive_lib_library OR NOT DEFINED libarchive_include)
        message(FATAL_ERROR "You need to specify the libarchive_lib_library and libarchive_include variables")
endif ()
target_include_directories(archive-cpp PUBLIC include ${libarchive_include})
target_link_libraries(archive-cpp PUBLIC ${libarchive_lib_library})

if (WIN32)
       set_target_properties(
               archive-cpp
               PROPERTIES
               WINDOWS_EXPORT_ALL_SYMBOLS ON
       )
endif ()
