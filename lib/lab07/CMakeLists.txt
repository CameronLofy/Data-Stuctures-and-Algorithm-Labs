set(HEADER_FILES
        inc/node.h
        inc/tree.h
	)

set(SOURCE_FILES
        src/tree.cpp
        )
include_directories(inc)
add_library(lab7_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
