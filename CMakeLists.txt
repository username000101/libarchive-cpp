cmake_minimum_required(VERSION 3.31)
project(libarchive_cpp)

set(CMAKE_CXX_STANDARD 23)


add_library(archive-cpp STATIC
        src/GetFiles.cpp
        src/Extract.cpp
)
if (NOT libarchive_library OR NOT libarchive_include)
	message(FATAL_ERROR "Need to specify the libarchive_library and libarchive_include variables")
endif ()
target_include_directories(archive-cpp PUBLIC ${libarchive_include} include)
target_link_libraries(archive-cpp PRIVATE ${libarchive_library})
