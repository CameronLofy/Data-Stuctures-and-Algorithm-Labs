#include "queue.h"
namespace lab5{
    queue::queue() {

    }

    queue::queue(std::string &data) {

    }

    queue::queue(const queue &original) {

    }

    queue::~queue() {

    }

    queue &queue::operator=(const queue &RHS) {
        //return <#initializer#>;
    }

    bool queue::isEmpty() const {
        return false;
    }

    unsigned queue::queueSize() const {
        return 0;
    }

    std::string queue::top() const {
        //return std::__cxx11::string();
    }

    void queue::enqueue(const std::string &data) {

    }

    void queue::dequeue() {

    }

    std::ostream& operator<<(std::ostream &stream, queue &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, queue &RHS) {
        return stream;
    }
}