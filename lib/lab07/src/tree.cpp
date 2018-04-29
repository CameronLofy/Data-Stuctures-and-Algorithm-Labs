#include <iostream>
#include "../inc/tree.h"
#include <sstream>
namespace lab7 {
    void clear(node *to_clear);
    int recur_get_freq(node* top, int key);
    unsigned maxDepth(node* top);
    struct node* newInsert(node* top, int key);
    struct node* get_node(node* top, int key);
    struct node* get_parent(node* top, node* key);
    bool has_children(node* key);
    unsigned recurLevel(node* top, int key);
    struct node* to_swap(node* top);
    bool in_tree_recur(node* top, int key);
    void recur_print(node* top);
    void recur_path_to(node* top, int key);
    std::vector<int> recur_values_above(node* top, int key, std::vector<int> &values);

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
            root = tmp;
        }
        newInsert(tempRoot, value);
        tree_size++;
    }

    // Remove key return true if the key is deleted, and false if it isn't in the tree
    bool tree::remove(int key) {
        if(!in_tree(key)){
            return false;
        }
        node* remove = get_node(root, key);
        node* remove_parent = get_parent(root, remove);

        if(remove->frequency > 1){
            remove->frequency--;
            tree_size--;
            return true;
        }
        if(!has_children(remove)){
            if(remove == root){
                clear(root);
            }
            delete remove;
            remove->frequency--;
            tree_size--;
            return true;
        }

        if(has_children(remove)) {
            node* toSwap = to_swap(remove);
            node* swap_parent = get_parent(root, toSwap);
            if (has_children(toSwap)) {
                swap_parent->right = toSwap->left;  //brings swap children up tree
            }
            if(remove->right == toSwap){    //If toSwap is one below remove
                toSwap->right = nullptr;    //don't want to have to_swap point to itself
                toSwap->left = remove->left;
            }
            else if(remove->left == toSwap){
                toSwap->left = nullptr;
                toSwap->right = remove->right;
            }
            else {
                toSwap->right = remove->right;
                toSwap->left = remove->left;
            }
            if(remove_parent == nullptr){
                root = toSwap;
            }
            else if(remove_parent->data > remove->data){
                remove_parent->right = toSwap;
            }
            else if(remove_parent->data < remove->data){
                remove_parent->left = toSwap;
            }
            remove->frequency--;
            delete remove;
            tree_size--;
            return true;
        }
        return false;
    }

    struct node* get_node(node* top, int key){
        if(top->data == key){
            return top;
        }
        else if(top->data > key){
            get_node(top->left, key);
        }
        else if(top->data < key){
            get_node(top->right, key);
        }
        else
            throw "Value not found in tree";
    }

    struct node* get_parent(node* top, node* key){
        if(top == key){
            return nullptr;
        }
        else if(top->right == key || top->left == key){
            return top;
        }
        else if(top->data < key->data){
            return get_parent(top->right, key);
        }
        else if(top->data > key->data){
            return get_parent(top->left, key);
        }
        throw "invalid node";
    }

    bool has_children(node* key){
        if(key->left != nullptr || key->right != nullptr){
            return true;
        }
        return false;
    }
    struct node* to_swap(node* top){
        if(top->left){
            top = top->left;    //gets highest node less than top
            while(top->right){  //node will never have a right node after loop
                top = top->right;
            }
            return top;
        }
        else {          //no left node, can just move everything under right node up
            top = top->right;
            return top;
        }
    }

    // What level is key on?
    int tree::level(int key) {
        if(in_tree(key)){
            return recurLevel(root, key);
        }
        return -1;
    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {
        if(in_tree(key)){
            recur_path_to(root, key);
            std::cout << std::endl;
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
        return in_tree_recur(root, key);

    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
        return recur_get_freq(root, key);
    }

    // Return a vector with all of the nodes that are greater than the input key in the tree
    std::vector<int> tree::values_above(int key) {
        std::vector<int> values_above = std::vector<int>();
        recur_values_above(root, key, values_above);
    }

    //Use the to string function for the following two functions
    // Print the tree least to greatest, Include duplicates
    void tree::print() {
        recur_print(root);
        std::cout << std::endl;

    }

    void recur_print(node* top){
        if(top == nullptr){
            return;
        }
        recur_print(top->left);
        for(int i =0; i<top->frequency; i++) {
            std::cout << top->data << " ";
        }
        recur_print(top->right);
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
        if(top == nullptr) return;
        node_print_gtl(top->right);
        for(int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
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

    bool in_tree_recur(node* top, int key) {
        if(top == nullptr){
            return false;
        }
        else if(top->data == key) {
            return true;
        }
        else if(key < top->data){
            return in_tree_recur(top->left, key);
        }
        else if(key > top->data) {
            return in_tree_recur(top->right, key);
        }
    }

    unsigned recurLevel(node* top, int key){
        if(top->data == key){
            return 0;
        }
        else{
            unsigned level;
            if(top->data < key){
                level = recurLevel(top->right, key);
                return (level+1);
            }
            else{
                level = recurLevel(top->left, key);
                return (level+1);
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

    int recur_get_freq(node* top, int key){
        if(top == nullptr) {
            return 0;
        }
        else if(top->data == key){
            return top->frequency;
        }
        else if(key > top->data){
            return recur_get_freq(top->right, key);
        }
        else if(key< top->data){
            return recur_get_freq(top->left, key);
        }
    }

    void recur_path_to(node* top, int key){
        std::cout << top->data;
        if(top->data == key){
            return;
        }
        else{
            std::cout << " -> ";
            if(top->data < key){
                recur_path_to(top->right, key);
            }
            else{
                recur_path_to(top->left, key);
            }
        }
    }

    std::vector<int> recur_values_above(node* top, int key, std::vector<int> &values){
        if(top == nullptr){
            return std::vector<int>();
        }
        //wil check every node value starting from the least value
        recur_values_above(top->left, key, values);
        int i = 0;
        while (i < top->frequency && top->data > key) {
            values.push_back(top->data);
            i++;
        }
        recur_values_above(top->right, key, values);
        return values;
        }
    }

    // Class function
    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }
};