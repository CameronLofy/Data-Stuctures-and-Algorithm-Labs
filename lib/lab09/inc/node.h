#ifndef CMPE126S18_LABS_LIB_LAB9_NODE_H
#define CMPE126S18_LABS_LIB_LAB9_NODE_H

namespace lab9{
    class node{
    private:
        char character;
        int frequency;
    public:
        node* next;
        node* prev;
        node* right;
        node* left;

        explicit node(char input){
            character = input;
            frequency = 1;
            next = nullptr;
            prev = nullptr;
            right = nullptr;
            left = nullptr;
        }

        node(node* input_left, node* input_right){
            //TODO: Implement this node constructor
        }

        // Accessors and Mutators for node
        char get_character(){ return character; }
        int get_frequency(){ return frequency; }
        void increment_frequency(){ frequency++; }

        // Only used in tree generation from string
        void set(char input_char){ character = input_char; }
    };
}

#endif //CMPE126S18_LABS_NODE_H
