set(HEADER_FILES
        inc/lifo.h
        inc/fifo.h)

set(SOURCE_FILES
        src/lifo.cpp
        src/fifo.cpp)

include_directories(inc)
add_library(lab3_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(lab3_lib lab2_lib)