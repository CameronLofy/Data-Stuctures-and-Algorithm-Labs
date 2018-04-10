#include "../inc/tree.h"
#include <iostream>

namespace lab7 {
    void clear(node *to_clear);
    unsigned maxDepth(node *top);
    struct node* newInsert(node* top, int key);

    // Construct an empty tree
    tree::tree() {
        root = nullptr;
        tree_size = 0;
    }

    // Copy constructor
    tree::tree(const tree &copy) {

    }

    // Deconstruct tree
    tree::~tree() {
        clear(root);
    }

    // Insert
    void tree::insert(int value) {
        node* tempRoot = root;
        if(tempRoot == NULL){
            node* tmp = new node(value);
            tmp->right = nullptr;
            tmp->left = nullptr;
            root = tmp;
        }
        newInsert(tempRoot, value);
        tree_size++;
    }

    // Remove key return true if the key is deleted, and false if it isn't in the tree
    bool tree::remove(int key) {

    }

    // What level is key on?
    int tree::level(int key) {
        int level = 0;
        node* current = root;
        if(current == nullptr){
            throw "Empty tree";
        }
        while(current->data != key){
            if(current->data > key){
                current = current->left;
                level++;
            }
            else if(current->data < key){
                current = current->right;
                level++;
            }
        }
        return level;
    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {
        std::vector<int> path = values_above(key);
        path.push_back(key);
        for(int i=0; i<=level(key); i++) {
            std::cout << path.at(i);
        }
    }

    // Number of items in the tree
    unsigned tree::size() {
        return tree_size;
    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
        node* tmpRoot = root;
        int depth = maxDepth(tmpRoot)-1;
        if(depth < 0){
            return 0;
        }
        return depth;
    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {
        if(get_frequency(key) == 0){
            return false;
        }
        else{
            return true;
        }

    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
        node* current = root;
        if(current == nullptr){
            return 0;
        }
        while(current->data != key){
            if(current->data > key){
                current = current->left;
            }
            else if(current->data < key){
                current = current->right;
            }
        }
        return current->frequency;


    }

    // Return a vector with all of the nodes that are greater than the input key in the tree
    std::vector<int> tree::values_above(int key) {
        node* current = root;
        std::vector<int> list;
        if(get_frequency(key)==0){
            throw "key not found in tree";
        }
        if(current->data == key){
            return list;
        }
        list.push_back(current->data);
        while(current->data != key){
            if(current->data > key){
                current = current->left;
                list.push_back(current->data);
            }
            else if(current->data < key){
                current = current->right;
                list.push_back(current->data);
            }
        }
        return list;

    }

    //Use the to string function for the following two functions
    // Print the tree least to greatest, Include duplicates
    void tree::print() {

    }

    // Print the tree least to greatest, Include duplicates
    std::ostream &operator<<(std::ostream &stream, tree &RHS) {

    }

    // Operator= Overload. Allowing for copying of trees
    tree &tree::operator=(const tree &rhs) {

    }

    /**************************
     * Extra credit functions *
     **************************/


    // Merge rhs into this. Demo to a TA for credit
    tree tree::operator+(const tree &rhs) const {

    }

    // Balance the tree using any published algorithm. Demo to a TA for credit
    void tree::balance() {

    }

    /*********************************************************************
     * Recursion Example                                                 *
     * Print the linked list from greatest to least using recursion      *
     *********************************************************************/

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

    unsigned maxDepth(node* top){
        if(top == nullptr){
            return 0;
        }
        else{
            int leftDepth = maxDepth(top->left);   //checks depth of left node
            int rightDepth = maxDepth(top->right); //checks depth of right node

            if(leftDepth > rightDepth){         //compares left and right depth of node
                return(leftDepth+1);            //returns left depth size if longer
            }
            else{                               //if right depth is longer or both are equal, return right depth length
                return(rightDepth+1);
            }
        }
    }

    struct node* newInsert(node* top, int key){
        if(top == nullptr){
            node* tmp = new node(key);
            tmp->right = nullptr;
            tmp->left = nullptr;
            return tmp;
        }
        else{
            if(key < top->data){
                top->left = newInsert(top->left, key);
            }
            else if(key > top->data){
                top->right = newInsert(top->right, key);
            }
            else{
                top->frequency++;
                return top;
            }
            return top;
        }
    }

    // Class function
    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }


}