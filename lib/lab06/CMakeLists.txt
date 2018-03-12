set(HEADER_FILES
        inc/node.h
        inc/doubly_linked_list.h)

set(SOURCE_FILES
        src/doubly_linked_list.cpp)
include_directories(inc)
add_library(lab6_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
#target_link_libraries(lab6_lib labXX_lib)