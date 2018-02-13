cmake_minimum_required(VERSION 3.9)
project(cmpe126s18_labs)

if(WIN32)
    if (CYGWIN)
        add_definitions(-std=gnu++0x)
    elseif(MINGW)
        add_definitions(-std=c++11)
    endif (CYGWIN)
endif(WIN32)
if(APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif(APPLE)

set(SOURCE_FILES main.cpp)

add_executable(labs_main ${SOURCE_FILES})

include_directories(lib/lab01/inc lib/lab02/inc lib/lab03/inc)

add_subdirectory(lib/lab01 lab1_lib)
add_subdirectory(lib/lab02 lab2_lib)
add_subdirectory(lib/lab03 lab3_lib)

add_subdirectory(test)

target_link_libraries(labs_main lab1_lib lab2_lib lab3_lib)