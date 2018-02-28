#include "stack.h"
namespace lab5{
    stack::stack() {

    }

    stack::stack(std::string &data) {

    }

    stack::stack(const stack &original) {

    }

    stack::~stack() {

    }

    stack &stack::operator=(const stack &RHS) {
        return <#initializer#>;
    }

    bool stack::isEmpty() const {
        return false;
    }

    unsigned stack::queueSize() const {
        return 0;
    }

    std::string stack::top() const {
        return std::__cxx11::string();
    }

    void stack::enqueue(const std::string &data) {

    }

    void stack::dequeue() {

    }

    std::ostream& operator<<(std::ostream &stream, stack &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, stack &RHS) {
        return stream;
    }
}