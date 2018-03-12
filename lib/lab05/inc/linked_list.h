#ifndef CMPE126S18_LABS_LIB_LAB05_INC_LINKED_LIST_H
#define CMPE126S18_LABS_LIB_LAB05_INC_LINKED_LIST_H

#include "node.h"
#include <iostream>

namespace lab5 {
    class linked_list {
        node *head, *tail;

    public:
        linked_list();

        explicit linked_list(std::string &data);

        linked_list(const linked_list &original);

        virtual ~linked_list();

        linked_list &operator=(const linked_list &RHS);

        friend std::ostream& operator<<(std::ostream& stream, linked_list& RHS);
        friend std::istream& operator>>(std::istream& stream, linked_list& RHS);

        bool isEmpty() const;
        unsigned listSize() const;

        std::string get_value_at(unsigned location);
        void insert(const std::string input, unsigned location = 0 );
        void append(const std::string input);
        void remove(unsigned location = 0);

        void sort();
    };
}

#endif