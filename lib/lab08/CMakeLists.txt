set(HEADER_FILES
        )

set(SOURCE_FILES
        )
include_directories(inc)
add_library(lab8_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
##target_link_libraries(lab8_lib lab##_lib)