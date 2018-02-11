#include "../inc/stringVector.h"

stringVector::stringVector() {          //Passed test
    data=nullptr;
    length=0;
    allocated_length=0;
}

stringVector::~stringVector() {         //Passed test
    delete[] data;
}

unsigned stringVector::size() {         //Passed test
    return length;
    //return ;
}

unsigned stringVector::capacity() {     //Passed test
    return allocated_length;
    //return ;
}

void stringVector::reserve(unsigned new_size) {     //Passed Test
    auto* temp= new std::string[new_size];

    //Copies data to temp, stops when reached new size or length
    for(int i=0;i<new_size && i<length;i++){
        temp[i] = data[i];
    }

    allocated_length = new_size;
    delete data;
    data = temp;

}

bool stringVector::empty() {        //Passed test
    if(length==0)
        return true;
    return false;
    //return ;
}

void stringVector::append(std::string new_data) {
    /*
    std::string*temp=nullptr;
    if(length==allocated_length){
        if(allocated_length==0){
            data=new std::string[1];
            allocated_length=1;
        }
        else{
            temp=new std::string[2*allocated_length];
            for(int i=0;i<length;i++){
                temp[i]=data[i];
            }
            allocated_length=2*allocated_length;
            if(data!=nullptr){
                delete[]data;
                data=temp;}
        }
    }
    data[length]=new_data;
    length++;
    */

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
        return;
    }
}





    /*
    int k = 0;
    while (new_data[k] < allocated_length) {
        data[length + 1] = new_data[k];
        length++;
        k++;
        if (length == allocated_length) {
            allocated_length = allocated_length * 2;
            data = new std::string[allocated_length];
        }
    }
}
*/



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
