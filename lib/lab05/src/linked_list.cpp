#include <linked_list.h>
namespace lab5 {
    linked_list::linked_list() {
        head = NULL;
        tail = NULL;

    }

    linked_list::linked_list(std::string &data) {
        node *temp = new node(data);
        head = temp;
        tail = head;
    }

    linked_list::linked_list(const linked_list &original) {     //copy constructor
        head = new node(original.head->data);
        tail = new node(original.tail->data);
        node *OG_temp = original.head;                      //TODO:: Fix this to make it actually work
        node *temp = head;
        while(OG_temp->next != NULL){
            OG_temp = OG_temp->next;
            temp->next = new node(OG_temp->data);
            temp = temp->next;
        }
    }

    linked_list::~linked_list() {
        while(head!=NULL){
            node *temp = head->next;
            delete head;
            head= temp;
        }
        tail = nullptr;
    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        if(this == &RHS){
            return *this;
        }
        head = new node(RHS.head->data);
        tail = new node(RHS.tail->data);
        node *temp = RHS.head;
        node *current = head;
        while (temp->next!=NULL) {
            temp = temp->next;
            current->next = new node(temp->data);
            current = current->next;
        }
        return *this;
    }


    bool linked_list::isEmpty() const {
        if(!head) {
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
        /*if(current == NULL && prev == NULL){
            throw "ERROR: Location not found";
        }*/
        if(current == NULL && prev){   //inserting after tail, reassigns ne tail
            prev->next = temp;
            temp->next = NULL;
            tail = temp;
        }
        else if(!current){              //inserting to an empty list
            head = temp;
            tail = temp;
        }

        else if (prev && current!=NULL) { // if a previous node exists
            prev->next = temp;
            temp->next = current;
        }
        else { // there is no previous node, temp is at at head
            head = temp;
            head->next = current;
        }
    }

    void linked_list::append(const std::string input) {
        node* current=head;
        if(head == NULL){
            node *temp = new node(input);
            head = temp;
            tail = temp;
        }
        else {
            while (current->next != NULL) {
                current = current->next;
            }
            node *temp = new node(input);
            current->next = temp;
            temp->next = NULL;
            tail = temp;
        }
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
        }
        if(location>listSize()){
            throw "ERROR: INPUT INTEGER TOO BIG FOR LIST";
        }
        else if(!prev){
            head = current->next;
        }
    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        int size = RHS.listSize();

        for (int i = 0; i < size; i++) {
            stream << RHS.get_value_at(i);
            stream << " -> ";
        }
        stream << "NULL";
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        std::string temp;
        getline(stream, temp);
        RHS.append(temp);
        return stream;
    }

    void linked_list::sort() {

        unsigned i,j;
        int size = listSize();

        for (j = 0; j < size-1; j++)
        {
            unsigned iMin = j;
            for (i = j+1; i < size; i++)
            {
                if (get_value_at(i) < get_value_at(iMin))
                {
                    iMin = i;
                }
            }

            if (iMin != j)
            {
                std::string temp_i(get_value_at(iMin));   //creates temporary string values
                std::string temp_j(get_value_at(j));

                remove(j);
                insert(temp_i, j);      //replaces the value at j with temp_i

                remove(iMin);
                insert(temp_j, iMin);      //replaces the value at i with temp_j
            }
        }
    }

    std::string linked_list::get_value_at(unsigned location) const{
        std::string value;
        node* current = head;
        for(int i=0; i<location; i++){
            current= current->next;
        }
        if(head == NULL){
            throw "ERROR: NO VALUES IN LINKED LIST";
        }
        value = current->data;
        return value;
    }
}