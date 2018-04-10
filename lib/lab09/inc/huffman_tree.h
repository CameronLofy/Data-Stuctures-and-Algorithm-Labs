#ifndef CMPE126S18_LABS_HUFFMAN_TREE_H
#define CMPE126S18_LABS_HUFFMAN_TREE_H

#include "node.h"
#include <string>
namespace lab9{
    class huffman_tree{
    private:
        node* root;
        node* head;
        node* tail;
        node* remove();

    public:
        huffman_tree();
        huffman_tree(std::string& dict_string_from_file);
        ~huffman_tree();

        void add(char character);
        void generate_tree();

        node* get_root();
        bool valid_tree();
    };
}

#endif //CMPE126S18_LABS_HUFFMAN_TREE_H
