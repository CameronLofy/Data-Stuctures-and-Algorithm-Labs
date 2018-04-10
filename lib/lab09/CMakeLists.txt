set(HEADER_FILES
        dict_entry.h
        huffman.h
        huffman_dictionary.h
        huffman_tree.h
        node.h
        )

set(SOURCE_FILES
        huffman.cpp
        huffman_dictionary.cpp
        huffman_tree.cpp
        )
include_directories(inc)
add_library(lab9_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
#target_link_libraries(lab9_lib labXX_lib)