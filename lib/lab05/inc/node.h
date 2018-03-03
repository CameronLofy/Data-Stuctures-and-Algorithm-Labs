#ifndef CMPE126S18_LABS_LIB_LAB5_NODE_H
#define CMPE126S18_LABS_LIB_LAB5_NODE_H
#include <string>

namespace lab5 {
    class node {
    public:
        node *next;
        std::string data;

        explicit node(const std::string &data) : data(data), next(nullptr){};
    };
}

#endif