#include <stdexcept>
#include "../inc/stringVector.h"

stringVector::stringVector() {          //Passed testing
    data=nullptr;
    length=0;
    allocated_length=0;
}

stringVector::~stringVector() {         //Passed testing
    delete[] data;
}

unsigned stringVector::size()const {         //Passed testing
    return length;
    //return ;
}

unsigned stringVector::capacity()const {     //Passed testing
    return allocated_length;
    //return ;
}

void stringVector::reserve(unsigned new_size) {     //Passed Testing
    auto* temp= new std::string[new_size];

    //Copies data to temp, stops when reached new size or length
    for(int i=0;i<new_size && i<length;i++){
        temp[i] = data[i];
    }

    allocated_length = new_size;
    delete[] data;
    data = temp;

}

bool stringVector::empty()const {        //Passed testing
    if(length==0)
        return true;
    return false;
    //return ;
}

void stringVector::append(std::string new_data) {       //Passed Testing
    //If empty string, reserve space for 1 then append
    if (allocated_length == 0) {
        this->reserve(1);
        this->append(new_data);
    }
    //Doubles the allocated size when too small
    else if (length == allocated_length) {
        this->reserve(2 * allocated_length);
        this->append(new_data);
    }

    else {
        data[length] = new_data;
        length++;
    }
    return;
}


void stringVector::swap(unsigned pos1, unsigned pos2) {
    if(pos1>length || pos2>length){
        throw(std::string("EXCEPTION THROWN"));
    }
    std::string temp = data[pos1];
    data[pos1] = data[pos2];
    data[pos2] = temp;

}

stringVector &stringVector::operator=(stringVector const &rhs) {
    if(&rhs == this){
        return(*this);
    }
    else{
        delete[] data;
        length = rhs.length;
        allocated_length = rhs.allocated_length;
        this->data = new std::string[allocated_length];
        for(int i=0; i<length; i++){
            this->data[i] = rhs.data[i];
        }
    }
    //return ;
}

std::string &stringVector::operator[](unsigned position) {      //Testing passed
    if(position >= allocated_length)
        throw 42;
    return data[position];
    //return ;
}

void stringVector::sort() {

}
