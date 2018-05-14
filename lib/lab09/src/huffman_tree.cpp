#include "../inc/huffman_tree.h"

namespace lab9{
    node *huffman_tree::remove() {
        node* temp = priority_head;
        if(temp == nullptr){
            throw "Priority queue empty";
        }
        if(temp->next == nullptr){
            priority_head = nullptr;
            priority_tail = nullptr;
            return temp;
        }
        priority_head = priority_head->next;
        priority_head->prev = nullptr;
        return temp;
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
        // TODO: Write the destructor. Make sure to clear out both the priority queue and the tree
    }

    void huffman_tree::add(char character) {
        node* add = new node(character);
        node* temp = priority_head;
        while(temp != nullptr){
            if(temp->get_character() == character){
                temp->increment_frequency();
                if(temp == priority_tail) {
                    return;
                }
                node* priority_temp = temp;
                while(priority_temp->get_frequency() < temp->get_frequency()){
                    if(priority_temp == priority_tail){
                        priority_tail->next = priority_temp;
                        priority_temp->prev = priority_tail;
                        priority_tail = priority_temp;
                        priority_temp->next = nullptr;
                        delete[] priority_temp;
                        return;
                    }
                    priority_temp = priority_temp->next;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->prev = priority_temp->prev;
                temp->next = priority_temp;
                priority_temp->prev->next = temp;
                priority_temp->prev = temp;
                delete[] temp;
                return;
            }
            temp = temp->next;
        }
        add->next = priority_head;
        priority_head->prev = add;
        priority_head = add;
    }

    void huffman_tree::generate_tree() {    //Not sure wat to do with this yet
        huffman_tree priority_queue;
        while(priority_head->get_frequency() == priority_head->next->get_frequency()) {
            node *left = priority_head;
            node *right = priority_head->next;
            node final = node(left, right);
        }

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
