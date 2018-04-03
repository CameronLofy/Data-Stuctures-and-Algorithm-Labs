#include "../inc/tree.h"
#include <iostream>

namespace lab7 {
    void clear(node *to_clear);

    // Construct an empty tree
    tree::tree() {
        root = nullptr;
    }

    // Deconstruct tree
    tree::~tree() {
        clear(root);
    }

    // Insert
    void tree::insert(int value) {

    }

    // Remove key
    bool tree::remove(int key) {

    }

    // What level is key on?
    int tree::level(int key) {

    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {

    }

    // Number of items in the tree
    unsigned tree::size() {

    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {

    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {

    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {

    }

    // Return a vector with all of the nodes that are greater than the input key in the tree
    std::vector<int> tree::values_above(int key) {

    }

    // Print the tree least to greatest, Include duplicates
    void tree::print() {

    }

    // Print the tree least to greatest, Include duplicates
    std::ostream &operator<<(std::ostream &stream, tree &RHS) {

    }

    // Operator= Overload. Allowing for copying of trees
    tree &tree::operator=(const tree &rhs) {

    }


    /*
     * Extra credit functions
     */

    // Merge rhs into this. Demo to a TA for credit
    tree tree::operator+(const tree &rhs) const {

    }

    // Balance the tree using any published algorithm. Demo to a TA for credit
    void tree::balance() {

    }

    /*
     * Recursion Example
     * Print the linked list from greatest to least using recursion
     */

    // Auxiliary functions
    void node_print_gtl(node *top) {
        if (top == nullptr) return;
        node_print_gtl(top->right);
        for (int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
        node_print_gtl(top->left);
    }

    void clear(node *to_clear) {
        if (to_clear == nullptr) return;
        if (to_clear->left != nullptr) clear(to_clear->left);
        if (to_clear->right != nullptr) clear(to_clear->right);
        delete to_clear;
    }

    // Class function
    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }


}