#ifndef CMPE126S18_LABS_LIB_LAB6_NODE_H
#define CMPE126S18_LABS_LIB_LAB6_NODE_H

namespace lab6{
    class node{
        int data;
    public:
        node* next;
        node* prev;
        explicit node(int input_data) : data(input_data), next(nullptr), prev(nullptr){};
        int get_data(){return data;};
    };
}

#endif //CMPE126S18_LABS_NODE_H
