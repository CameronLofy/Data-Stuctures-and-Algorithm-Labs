#include "fifo.h"

namespace lab3{
    fifo::fifo() {
        front_index = 0;
        back_index = 99;
        lab2::stringVector fifo_storage;
        fifo_storage.lab2::reserve(100);
    }

    fifo::fifo(std::string input_string) {
        front_index = 0;
        back_index = 99;
        lab2::stringVector fifo_storage;
        fifo_storage.lab2::reserve(100);
        fifo_storage.lab2::append(input_string);
    }

    fifo::fifo(const fifo &original) {
        front_index = 0;
        back_index = 99;
        lab2::stringVector fifo_storage;
        fifo_storage.lab2::


    }

    fifo::~fifo() {
        delete fifo_storage;

    }

    fifo &fifo::operator=(const fifo &right) {
        //return <#initializer#>;
    }

    bool fifo::is_empty() const {
        //return false;
    }

    unsigned fifo::size() const {
        //return 0;
    }

    std::string fifo::top() const {
        //return std::__cxx11::string();
    }

    void fifo::enqueue(std::string input) {

    }

    void fifo::dequeue() {

    }
}