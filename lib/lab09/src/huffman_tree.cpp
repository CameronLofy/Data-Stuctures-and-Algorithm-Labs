#include "../inc/huffman_tree.h"

namespace lab9{
    node *huffman_tree::remove() {
        // TODO: Write function that removes the first node form the priority queue and returns it
        return nullptr;
    }

    huffman_tree::huffman_tree() {
        root = nullptr;
        priority_head = nullptr;
        priority_tail = nullptr;
    }

    huffman_tree::huffman_tree(std::string &dict_string_from_file) {
        // Constructor that parses in the huffman dictionary from the file and creates the tree

        // State machine variable declarations
        const int default_state = 0, character_state = 1, tree_state = 2;
        int state = default_state;
        bool first_quote = false, second_quote = false;
        char key = 0;

        // Create our current node* and set it to root which is nullptr
        node* current = root;
        for(char c: dict_string_from_file) {
            switch(state) {
                case character_state:
                    switch (c) {
                        case '\'': {
                            if (!first_quote) first_quote = true;
                            else if (!second_quote) second_quote = true;
                            else key = c;
                        }
                            break;
                        case ':': {
                            if (first_quote && second_quote) {
                                state = tree_state;
                                first_quote = false;
                                second_quote = false;
                            } else key = c;
                        }
                            break;
                        default:
                            key = c;
                            break;
                    }
                    break;
                case tree_state:
                    switch (c) {
                        case ',': {
                            current->set(key);
                            current = root;
                            state = default_state;
                        }
                            break;
                        case '0': {
                            if (current->left == nullptr) current->left = new node('\0');
                            current = current->left;
                        }
                            break;
                        case '1': {
                            if (current->right == nullptr) current->right = new node('\0');
                            current = current->right;
                        }
                            break;
                        default:
                            return;
                    }
                    break;
                default:
                    if (c == '\'') {
                        state = character_state;
                        first_quote = true;
                    }
                    break;
            }
        }
        current->set(key);
    }

    huffman_tree::~huffman_tree() {
        // TODO: Write the desctructor. Make sure to clear out both the priority queue and the tree
    }

    void huffman_tree::add(char character) {
        // TODO: Add the character to the priority queue, increasing the frequency if needed
    }

    void huffman_tree::generate_tree() {
        // TODO: Generate the tree from the priority queue
    }

    node *huffman_tree::get_root() {
        // So complicated
        return root;
    }

    bool huffman_tree::valid_tree() {
        // TODO: Check to see if priority_head is null and root isn't
    }
}
