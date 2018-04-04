#include "stack.h"
namespace lab5{
    stack::stack() {

    }

    stack::stack(std::string &data) {
        storage_structure.insert(data, 0);
    }

    stack::stack(const stack &original) {
        stack temp;
        temp = original;
        for(int i=0; i<temp.stackSize(); i++){
            storage_structure.append(temp.top());
            temp.pop();
        }

    }

    stack::~stack() {
        for(int i=0; i<storage_structure.listSize(); i++){
            storage_structure.remove(i);
        }
    }

    stack &stack::operator=(const stack &RHS) {
        for(int i=0; i<RHS.stackSize(); i++) {
            this->storage_structure.append(RHS.storage_structure.get_value_at(i));
        }
        return *this;
        //return <#initializer#>;
    }

    bool stack::isEmpty() const {
        if(storage_structure.isEmpty()){
            return true;
        }
        return false;
    }

    unsigned stack::stackSize() const {
        return storage_structure.listSize();
    }

    std::string stack::top() const {
        return storage_structure.get_value_at(0);
        //return std::__cxx11::string();
    }

    void stack::push(const std::string &data) {
        storage_structure.insert(data, 0);

    }

    void stack::pop() {
        storage_structure.remove(0);

    }

    std::ostream& operator<<(std::ostream &stream, stack &RHS) {
        stream << std::string("Stack: ");
        for(int i=0; i<RHS.stackSize(); i++){
            stream << RHS.storage_structure.get_value_at(i);
            stream << " ";
        }
        return stream;
    }

    std::istream& operator>>(std::istream &stream, stack &RHS) {
        std::string temp;
        getline(stream, temp);
        RHS.storage_structure.insert(temp, 0);
        return stream;
    }
}