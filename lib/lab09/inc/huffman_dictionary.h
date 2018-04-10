#ifndef CMPE126S18_LABS_HUFFMAN_DICTIONARY_H
#define CMPE126S18_LABS_HUFFMAN_DICTIONARY_H

#include "node.h"
#include "dict_entry.h"
#include <string>
#include <iostream>
#include <sstream>
namespace lab9{
    class huffman_dictionary{
    private:
        dict_entry hash_table[];

    public:
        huffman_dictionary(node* huffman_tree_root);
        ~huffman_dictionary();

        std::string get(char input_key);
        std::string to_string();
        friend std::ostream& operator<<(std::ostream& stream, huffman_dictionary& RHS);
    };
}

#endif //CMPE126S18_LABS_HUFFMAN_DICTIONARY_H
