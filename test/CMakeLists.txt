cmake_minimum_required(VERSION 2.8)

set(SOURCE_FILES
        testcases.c)

add_executable(testcases ${SOURCE_FILES})
target_link_libraries(testcases csafestring)

add_test(NAME test_createEmtpy COMMAND testcases test_createEmpty)
add_test(NAME test_createFull COMMAND testcases test_createFull)
add_test(NAME test_concatination COMMAND testcases test_concatination)
add_test(NAME test_copy COMMAND testcases test_copy)
add_test(NAME test_clone COMMAND testcases test_clone)
add_test(NAME test_strchrappend COMMAND testcases test_strchrappend)
add_test(NAME test_emptyDestroy COMMAND testcases test_emptyDestroy)
add_test(NAME test_initialSizeOfAllocation COMMAND testcases test_initialSizeOfAllocation)
