set(HEADER_FILES
        inc/stringVector.h)

set(SOURCE_FILES
        src/stringVector.cpp)
include_directories(inc)
add_library(lab2_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})