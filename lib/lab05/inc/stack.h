#ifndef CMPE126S18_LABS_LIB_LAB05_INC_STACK_H
#define CMPE126S18_LABS_LIB_LAB05_INC_STACK_H

#include "linked_list.h"
namespace lab5 {
    class stack {
    private:
        linked_list storage_structure;

    public:
        stack();
        stack(std::string &data);
        stack(const stack &original);
        virtual ~stack();
        stack &operator=(const stack &RHS);

        bool isEmpty() const;
        unsigned stackSize() const;

        std::string top() const;

        void push(const std::string &data);

        void pop();

        friend std::ostream& operator<<(std::ostream& stream, stack& RHS);
        friend std::istream& operator>>(std::istream& stream, stack& RHS);
    };
}
#endif
