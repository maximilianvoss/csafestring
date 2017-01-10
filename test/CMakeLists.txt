cmake_minimum_required(VERSION 2.8)

set(SOURCE_FILES
        testcases.c)

add_executable(testcases ${SOURCE_FILES})
target_link_libraries(testcases csafestring)

add_test(NAME createEmtpy COMMAND testcases createEmpty)
add_test(NAME createFull COMMAND testcases createFull)
add_test(NAME concatination COMMAND testcases concatination)
add_test(NAME copy COMMAND testcases copy)
add_test(NAME clone COMMAND testcases clone)
add_test(NAME strchrappend COMMAND testcases strchrappend)
