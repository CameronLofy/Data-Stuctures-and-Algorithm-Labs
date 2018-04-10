#ifndef CMPE126S18_LABS_TREE_H
#define CMPE126S18_LABS_TREE_H
#include "node.h"
#include <iostream>
#include <vector>

namespace lab7 {
    class tree {
        node *root;
        int tree_size;
    public:
        tree();
        tree(const tree& copy);     //Recursively
        ~tree();                    //Recursively

        void insert(int value);     //Recursively
        bool remove(int key);
        bool in_tree(int key);      //Recursively
        int get_frequency(int key); //Recursively

        std::string to_string();    //Recursively
        int level(int key);         //Recursively
        void path_to(int key);      //Recursively
        unsigned size();
        unsigned depth();           //Recursively
        void print();               //Recursively

        tree& operator=(const tree &rhs);   //Recursively
        friend std::ostream& operator<<(std::ostream& stream, tree& RHS); //Recursively

        // Extra credit
        std::vector<int> values_above(int key); //Recursively
        tree operator+(const tree &rhs) const;  //Recursively
        void balance();

        // Example recursion
        void print_gtl();
    };
}

#endif //CMPE126S18_LABS_TREE_H
