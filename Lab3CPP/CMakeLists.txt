add_executable(Lab3CPP task.cpp)
target_include_directories(Lab3CPP PUBLIC ../LibraryCPP)
target_link_libraries(Lab3CPP LibraryCPP)

enable_testing()

add_test(
    NAME Lab3Test1
    COMMAND Lab3CPP
    ${CMAKE_CURRENT_SOURCE_DIR}/input1.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/output1.txt
)

add_test(
    NAME Lab3Test2
    COMMAND Lab3CPP
    ${CMAKE_CURRENT_SOURCE_DIR}/input2.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/output2.txt
)

add_test(
    NAME Lab3Test3
    COMMAND Lab3CPP
    ${CMAKE_CURRENT_SOURCE_DIR}/input3.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/output3.txt
)