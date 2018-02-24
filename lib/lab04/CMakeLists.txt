set(HEADER_FILES
        inc/calculator.h)

set(SOURCE_FILES
        src/calculator.cpp)
include_directories(inc)
add_library(lab4_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(lab4_lib lab1_lib)
target_link_libraries(lab4_lib lab3_lib)
