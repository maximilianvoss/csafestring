cmake_minimum_required(VERSION 3.6)
project(csafestring)

set(SOURCE_FILES
    csafestring.c csafestring.h)

add_library(csafestring ${SOURCE_FILES})
target_link_libraries(csafestring)

install(TARGETS csafestring DESTINATION /usr/local/lib)
install(FILES csafestring.h DESTINATION /usr/local/include)

