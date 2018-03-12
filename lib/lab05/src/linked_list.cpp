#include <linked_list.h>
namespace lab5 {
    linked_list::linked_list() {
        head = NULL;
        tail = NULL;

    }

    linked_list::linked_list(std::string &data) {
        head->data = data;
        tail = head;
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
        while(head!=NULL){
            node *temp = head->next;
            delete head;
            head= temp;
        }
        tail = nullptr;
    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        node *copy = RHS.head;
        node *current = new node(copy->data);
        while(current->next!=NULL){
            current = current->next;
            copy = copy->next;
            current->data = copy->data;
        }


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
        }

        else { // there is no previous node, temp is at at head
            head = temp;
            head->next = current;
        }
        delete temp;


    }

    void linked_list::append(const std::string input) {
        node *temp = new node(input);
        tail->next = temp;
        tail = tail->next;
        tail->next = NULL;

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
            head = current->next;
        }


    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        int size = RHS.listSize();

        stream << std::string("Linked List: ");
        for (int i = 0; i < size; i++) {
            stream << RHS.get_value_at(i);
            stream << " ";
        }
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        std::string temp;
        getline(stream, temp);
        RHS.append(temp);
        return stream;
    }

    void linked_list::sort() {

        int i,j;
        int size = listSize();
        std::string temp;

        for (j = 0; j < size-1; j++)
        {
            int iMin = j;
            for (i = j+1; i < size; i++)
            {
                if (get_value_at(i) < get_value_at(iMin))
                {
                    iMin = i;
                }
            }

            if (iMin != j)
            {
                std::string temp_i = get_value_at(i);   //creates temporary string values
                std::string temp_j = get_value_at(j);

                remove(j);
                insert(temp_i, j);      //replaces the value at j with temp_i

                remove(i);
                insert(temp_j, i);      //replaces the value at i with temp_j
            }
        }
    }

    std::string linked_list::get_value_at(unsigned location) const{
        std::string value =0;
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