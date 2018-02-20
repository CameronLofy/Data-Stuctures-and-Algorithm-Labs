#include "fifo.h"

namespace lab3{
    fifo::fifo() {
        front_index = 0;
        back_index = 0;
        fifo_storage.reserve(100);

    }

    fifo::fifo(std::string input_string) {
        front_index = 0;
        back_index = 1;
        fifo_storage.reserve(100);
        fifo_storage.append(input_string);

    }

    fifo::fifo(const fifo &original) {
        fifo_storage.reserve(100);
        front_index = original.front_index;
        back_index = original.back_index;
        for(int i=0; i<back_index; i++){
            fifo_storage[i] = original.fifo_storage[i];
        }

    }

    fifo::~fifo() {
        fifo_storage.reserve(0);
        front_index = 0;
        back_index = 0;

    }

    fifo &fifo::operator=(const fifo &right) {
        if (&right == this){
            return (*this);
        }
        fifo_storage.reserve(right.fifo_storage.capacity());
        front_index = right.front_index;
        back_index = right.back_index;
        for(int i = 0; i<right.fifo_storage.size(); i++){
            fifo_storage[i] = right.fifo_storage[i];
        }
        //return <#initializer#>;

    }

    bool fifo::is_empty() const {
        return front_index >= back_index;
    }

    unsigned fifo::size() const {
        if(!is_empty())
            return back_index - front_index;
        else
            return 0;
    }

    std::string fifo::top() const {
        return fifo_storage[front_index];

    }

    void fifo::enqueue(std::string input) {
        fifo_storage.append(input);
        back_index++;

    }

    void fifo::dequeue() {
        if(!is_empty()) {
            front_index++;
        }
        else
            throw (std::string("ERROR: Empty"));

    }
}