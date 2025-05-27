cmake_minimum_required(VERSION 3.31)
project(libarchive_cpp)

set(CMAKE_CXX_STANDARD 23)

find_package(PkgConfig)

add_library(archive-cpp STATIC
        src/GetFiles.cpp
        src/Extract.cpp
)

if (PkgConfig_FOUND)
    pkg_check_modules(LIBARCHIVE QUIET)
    if (LIBARCHIVE_FOUND)
        target_link_libraries(archive-cpp PRIVATE ${LIBARCHIVE_LIBRARIES})
    else ()
        if (libarchive_library)
            target_link_libraries(archive-cpp PRIVATE ${libarchive_library})
        else ()
            message(FATAL_ERROR "You need to specify the libarchive_library variable or install libarchive with PkgConfig")
        endif ()
    endif ()
else ()
    if (libarchive_library)
        target_link_libraries(libarchive-cpp PRIVATE ${libarchive_library})
    else ()
    endif ()
endif ()

target_include_directories(archive-cpp PUBLIC include)
