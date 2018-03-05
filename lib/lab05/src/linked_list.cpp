#include <linked_list.h>
namespace lab5 {
    linked_list::linked_list() {
        head = NULL;
        tail = NULL;

    }

    linked_list::linked_list(std::string &data) {
        head->data = data;
    }

    linked_list::linked_list(const linked_list &original) {     //copy constructor
        node *OG_temp = original.head;
        node *temp = head;
        tail = original.tail;
        for(int i=0; i< original.listSize(); i++) {
            temp->data = OG_temp->data;
            temp->next = OG_temp->next;
        }
    }

    linked_list::~linked_list() {

    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        //return <#initializer#>;
    }


    bool linked_list::isEmpty() const {
        if(head == NULL && tail == NULL) {
            return true;
        }
        return false;
    }

    unsigned linked_list::listSize() const {
        int size = 0;
        node *temp = head;
        if(isEmpty()){
            return 0;
        }
        while(temp!=NULL){
            temp = temp->next;
            size++;
        }
        return size;
    }

    void linked_list::insert(const std::string input, unsigned int location) {
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
        delete temp;


    }

    void linked_list::append(const std::string input) {
        node *temp = new node(input);
        node *tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        tail->next = temp;

        delete temp;


    }

    void linked_list::remove(unsigned location) {
        node *prev=NULL;
        node *current;
        current = head;
        //make for loop to find location,
        for(int i = 0; i < location; i++) { // iterate to the location of the node you want to delete
            prev = current;
            current = current->next;
        }
        if (prev) { // if a previous node exists
            prev->next = current->next;
            current = NULL;
            delete current;
        }
        if(location>=listSize()){
            throw "ERROR: INPUT INTEGER TOO BIG FOR LIST";
        }
        else {
            node *temp = current;
            temp->next = current;
            delete head;
            head = temp;
        }


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