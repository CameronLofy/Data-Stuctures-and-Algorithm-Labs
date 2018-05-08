include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests
        lab01_tests.cpp
        lab02_tests.cpp
        lab03_tests.cpp
        lab04_tests.cpp
        lab05_tests.cpp
        lab06_tests.cpp
        lab07_tests.cpp
#        lab08_tests.cpp #uncomment this line to test lab 8, google will fail the test if it is empty
        )

add_subdirectory(gtest-1.7.0)

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(runBasicTests
        lab1_lib
        lab2_lib
        lab3_lib
        lab4_lib
        lab5_lib
        lab6_lib
        lab7_lib
        lab8_lib
        )