#include "../inc/stringVector.h"

stringVector::stringVector() {
    data=nullptr;
    length=0;
    allocated_length=0;
}

stringVector::~stringVector() {
    delete[] data;
}

unsigned stringVector::size() {
    return length;
    //return ;
}

unsigned stringVector::capacity() {
    return allocated_length;
    //return ;
}

void stringVector::reserve(unsigned new_size) {
    std::string* temp= new std::string[new_size];
    for(int i=0;i<new_size && i<length;i++){
        temp[i] = data[i];
    }
    allocated_length = new_size;
    delete data;
    data = temp;

}

bool stringVector::empty() {
    if(length==0)
        return true;
    //return ;
}

void stringVector::append(std::string new_data) {
    int k=0;
    while(new_data[k] != '\0')
        data[length+k] = new_data[k];
        k++;
        if(length+k == allocated_length)
            allocated_length = allocated_length*2;
            data = new std::string [allocated_length];
    data[k+1] = "\0";

}

void stringVector::swap(unsigned pos1, unsigned pos2) {
    unsigned temp = pos1;
    pos1 = pos2;
    pos2 = temp;

}

stringVector &stringVector::operator=(stringVector const &rhs) {
    //return ;
}

std::string &stringVector::operator[](unsigned position) {
    //return ;
}

void stringVector::sort() {

}
