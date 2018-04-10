set(HEADER_FILES
        inc/hash_table.h)

set(SOURCE_FILES
        src/hash_table.cpp
        src/sorts.cpp)
include_directories(inc)
add_library(lab8_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(lab8_lib lab6_lib)