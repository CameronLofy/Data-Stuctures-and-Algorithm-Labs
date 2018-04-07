#include "queue.h"
namespace lab5{
    queue::queue() {

    }

    queue::queue(std::string &data) {
        storage_structure.append(data);

    }

    queue::queue(const queue &original) {
        queue temp;
        temp = original;
        for(int i=0; i<original.queueSize(); i++){
            storage_structure.append(temp.top());
            temp.dequeue();
        }
    }

    queue::~queue() {
        for(int i=0; i<storage_structure.listSize(); i++){
            storage_structure.remove(i);
        }

    }

    queue &queue::operator=(const queue &RHS) {
        if(this == &RHS){
            return *this;
        }
        while(!this->isEmpty()){
            this->dequeue();
        }
        for(int i=0; i<RHS.queueSize(); i++) {
            this->storage_structure.append(RHS.storage_structure.get_value_at(i));
        }
        return *this;
    }

    bool queue::isEmpty() const {
        if(storage_structure.isEmpty()){
            return true;
        }
        return false;
    }

    unsigned queue::queueSize() const {
        return storage_structure.listSize();
    }

    std::string queue::top() const {
        return storage_structure.get_value_at(0);
    }

    void queue::enqueue(const std::string &data) {
        storage_structure.append(data);
    }

    void queue::dequeue() {
        storage_structure.remove(0);
    }

    std::ostream& operator<<(std::ostream &stream, queue &RHS) {
        stream << std::string("Queue: ");
        for(int i=0; i<RHS.queueSize(); i++){
            stream << RHS.storage_structure.get_value_at(i);
            stream << " ";
        }
        return stream;
    }

    std::istream& operator>>(std::istream &stream, queue &RHS) {
        std::string temp;
        getline(stream, temp);
        RHS.storage_structure.append(temp);
        return stream;
    }
}