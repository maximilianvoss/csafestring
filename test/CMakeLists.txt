cmake_minimum_required(VERSION 2.8)

set(SOURCE_FILES
        testcases.c)

add_executable(csafestring_testcases ${SOURCE_FILES})
target_link_libraries(csafestring_testcases csafestring)

add_test(NAME test_createEmtpy COMMAND csafestring_testcases test_createEmpty)
add_test(NAME test_createFull COMMAND csafestring_testcases test_createFull)
add_test(NAME test_concatination COMMAND csafestring_testcases test_concatination)
add_test(NAME test_copy COMMAND csafestring_testcases test_copy)
add_test(NAME test_clone COMMAND csafestring_testcases test_clone)
add_test(NAME test_strchrappend COMMAND csafestring_testcases test_strchrappend)
add_test(NAME test_emptyDestroy COMMAND csafestring_testcases test_emptyDestroy)
add_test(NAME test_initialSizeOfAllocation COMMAND csafestring_testcases test_initialSizeOfAllocation)
