#include "lifo.h"

namespace lab3{
    lifo::lifo() {
        lifo_storage.reserve(100);
        index = 0;
    //Reserve 100 spaces in lifo_storage
    }

    lifo::lifo(std::string input_string) {
        lifo_storage.reserve(100);
        index = 1;
        lifo_storage.append(input_string);

    }

    lifo::lifo(const lifo &original) {
        lifo_storage.reserve(100);
        index = original.index;
        for(int i=0; i<index; i++){
            lifo_storage[i] = original.lifo_storage[i];
        }

    }

    lifo::~lifo() {
        lifo_storage.reserve(0);
        index = 0;

    }

    lifo &lifo::operator=(const lifo &right) {
        if (&right == this){
            return (*this);
        }
        lifo_storage.reserve(right.lifo_storage.capacity());
        index = right.index;
        for(int i = 0; i<right.lifo_storage.size(); i++){
            lifo_storage[i] = right.lifo_storage[i];
        }
        //return <#initializer#>;
    }

    bool lifo::is_empty() const {
        return index == 0;
    }

    unsigned lifo::size() const {
        if(!is_empty()) {
            return index;
        }
    }

    std::string lifo::top() const {
        return lifo_storage[index-1];
    }

    void lifo::push(std::string input) {
        lifo_storage.append(input);
        index++;

    }

    void lifo::pop() {
        index--;

    }
}