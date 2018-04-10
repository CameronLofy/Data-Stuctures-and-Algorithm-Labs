
#ifndef CMPE126S18_LABS_HUFFMAN_H
#define CMPE126S18_LABS_HUFFMAN_H

#include <string>
#include "huffman_tree.h"
#include "huffman_dictionary.h"

namespace lab9{
    class huffman{
    public:
        huffman() = default;
        ~huffman() = default;
        void compress(std::string input_file, std::string output_file);
        void decompress(std::string input_file, std::string output_file);
    };
}

#endif //CMPE126S18_LABS_HUFFMAN_H
