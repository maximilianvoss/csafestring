cmake_minimum_required(VERSION 2.8)
project(csafestring)

set(SOURCE_FILES
        csafestring.c csafestring.h)

#set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3")

if (NOT nofpic)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3 -fPIC")
endif ()

if (NOT TARGET csafestring)
    add_library(csafestring ${SOURCE_FILES})
    target_link_libraries(csafestring)
    install(TARGETS csafestring DESTINATION lib)
    install(FILES csafestring.h DESTINATION include)
endif ()

enable_testing()
add_subdirectory(test)
add_subdirectory(example)

