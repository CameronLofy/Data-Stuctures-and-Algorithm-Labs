#ifndef CMPE126S18_LABS_DOUBLY_LINKED_LIST_H
#define CMPE126S18_LABS_DOUBLY_LINKED_LIST_H
#include "node.h"
#include <vector>
#include <iostream>

namespace lab6{
    class doubly_linked_list{
        lab6::node *head;
        lab6::node *tail;
    public:
        doubly_linked_list();
        doubly_linked_list(int input);
        doubly_linked_list(std::vector<int> vector_input);
        doubly_linked_list(const doubly_linked_list &original);
        ~doubly_linked_list();

        int get_data(unsigned position);
        std::vector<int> get_set(unsigned position_from, unsigned position_to);

        unsigned size();
        bool is_empty();

        void append(int input);
        void insert(int input, unsigned location = 0);
        void remove(unsigned location);

        doubly_linked_list split(unsigned position);
        doubly_linked_list split_set(unsigned position_1, unsigned position_2);

        void swap(unsigned position_1, unsigned position_2);
        void swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start, unsigned location_2_end);

        void sort();

        doubly_linked_list operator+(const doubly_linked_list &rhs) const;
        doubly_linked_list& operator=(const doubly_linked_list &rhs);
        doubly_linked_list& operator+=(const doubly_linked_list &rhs);
        bool operator==(const doubly_linked_list &rhs);

        friend std::ostream& operator<<(std::ostream& stream, doubly_linked_list& RHS);
        friend std::istream& operator>>(std::istream& stream, doubly_linked_list& RHS);
    };
}

#endif //CMPE126S18_LABS_DOUBLY_LINKED_LIST_H
