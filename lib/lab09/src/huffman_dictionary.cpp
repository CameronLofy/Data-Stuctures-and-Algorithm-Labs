#include "../inc/huffman_dictionary.h"

namespace lab9{
    huffman_dictionary::huffman_dictionary(node *huffman_tree_root) {
        //TODO: Generate the dictionary from the provided tree root node
    }

    huffman_dictionary::~huffman_dictionary() {
        //TODO: Delete all of the items in the dictionary
    }

    std::string huffman_dictionary::get(char input_key) {
        //TODO: Return the binary string for the given character
        return std::string();
    }

    std::string huffman_dictionary::to_string() {
        //TODO: Generate output string of dictionary. Follow the tests
        return std::string();
    }

    std::ostream &operator<<(std::ostream &stream, huffman_dictionary &RHS) {
        //TODO: Implement the ostream operator. Used in tree::compress
        //Hint: Use your to_string function
        return stream;
    }
}
