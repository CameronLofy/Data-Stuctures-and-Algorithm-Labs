set(HEADER_FILES
        inc/expressionstream.h)

set(SOURCE_FILES
        src/expressionstream.cpp)
include_directories(inc)
add_library(lab1_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})