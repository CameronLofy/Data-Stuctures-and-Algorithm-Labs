#include <linked_list.h>
namespace lab5 {
    linked_list::linked_list() {

    }

    linked_list::linked_list(std::string &data) {

    }

    linked_list::linked_list(const linked_list &original) {     //copy constructor

    }

    linked_list::~linked_list() {

    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        //return <#initializer#>;
    }


    bool linked_list::isEmpty() const {
        return false;
    }

    unsigned linked_list::listSize() const {
        return 0;
    }

    void linked_list::insert(const std::string input, unsigned int location) {      //TODO:: make location point
        node *prev=NULL;
        node *current;
        node *temp = new node(input);
        current = head;
        //make for loop to find location,
        for(int i = 0; i < location; i++) { // iterate to the two nodes you want to insert between
            prev = current;
            current = current->next;
        }
        if (prev) { // if a previous node exists
            prev->next = temp;
            temp->next = current;
        } else { // there is no previous node, temp is at at head
            head = temp;
           temp->next = current;
        }


    }

    void linked_list::append(const std::string input) {

    }

    void linked_list::remove(unsigned location) {

    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        return stream;
    }

    void linked_list::sort() {

    }
}