cmake_minimum_required(VERSION 2.8)

set(SOURCE_FILES
        testcases.c)

add_executable(${CMAKE_PROJECT_NAME}_testcases ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME}_testcases csafestring)

add_test(NAME test_createEmtpy COMMAND ${CMAKE_PROJECT_NAME}_testcases test_createEmpty)
add_test(NAME test_createFull COMMAND ${CMAKE_PROJECT_NAME}_testcases test_createFull)
add_test(NAME test_concatination COMMAND ${CMAKE_PROJECT_NAME}_testcases test_concatination)
add_test(NAME test_copy COMMAND ${CMAKE_PROJECT_NAME}_testcases test_copy)
add_test(NAME test_clone COMMAND ${CMAKE_PROJECT_NAME}_testcases test_clone)
add_test(NAME test_strchrappend COMMAND ${CMAKE_PROJECT_NAME}_testcases test_strchrappend)
add_test(NAME test_emptyDestroy COMMAND ${CMAKE_PROJECT_NAME}_testcases test_emptyDestroy)
add_test(NAME test_initialSizeOfAllocation COMMAND ${CMAKE_PROJECT_NAME}_testcases test_initialSizeOfAllocation)
