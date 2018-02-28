#ifndef CMPE126S18_LABS_LIB_LAB05_INC_QUEUE_H
#define CMPE126S18_LABS_LIB_LAB05_INC_QUEUE_H

#include "linked_list.h"
namespace lab5 {
    class queue {
    private:
        linked_list storage_structure;

    public:
        queue();
        queue(std::string &data);
        queue(const queue &original);
        virtual ~queue();
        queue &operator=(const queue &RHS);

        bool isEmpty() const;
        unsigned queueSize() const;

        std::string top() const;
        void enqueue(const std::string &data);
        void dequeue();

        friend std::ostream& operator<<(std::ostream& stream, queue& RHS);
        friend std::istream& operator>>(std::istream& stream, queue& RHS);
    };
}
#endif