set(HEADER_FILES
        inc/node.h
        inc/linked_list.h
        inc/stack.h
        inc/queue.h
		inc/fancy_calculator.h
        )

set(SOURCE_FILES
		src/linked_list.cpp
        src/stack.cpp
        src/queue.cpp
        src/fancy_calculator.cpp
		)
include_directories(inc)
add_library(lab5_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(lab5_lib lab1_lib)