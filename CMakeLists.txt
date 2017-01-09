cmake_minimum_required(VERSION 2.8)
project(csafestring)

set(SOURCE_FILES
        csafestring.c csafestring.h)

set(CMAKE_VERBOSE_MAKEFILE on)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -O3")

if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDEBUG")
    add_executable(csafestring ${SOURCE_FILES})
else (${CMAKE_BUILD_TYPE} STREQUAL Release)
    add_library(csafestring ${SOURCE_FILES})
    target_link_libraries(csafestring)
    install(TARGETS csafestring DESTINATION /usr/local/lib)
    install(FILES csafestring.h DESTINATION /usr/local/include)
endif (${CMAKE_BUILD_TYPE} STREQUAL Debug)

