cmake_minimum_required(VERSION 2.8)

set(SOURCE_FILES
        example.c)

if ( NOT TARGET csafestring_example)
    add_executable(csafestring_example ${SOURCE_FILES})
    target_link_libraries(csafestring_example csafestring)
endif()    
