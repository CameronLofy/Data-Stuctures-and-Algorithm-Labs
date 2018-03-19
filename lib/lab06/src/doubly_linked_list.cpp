#include "../inc/doubly_linked_list.h"

namespace lab6{
    doubly_linked_list::doubly_linked_list() {
        head = NULL;
        tail = NULL;
    }

    doubly_linked_list::doubly_linked_list(int input) {
        head = new node(input);
        tail = new node(input);
    }

    doubly_linked_list::doubly_linked_list(std::vector<int> vector_input) {
        if(vector_input.empty()){
            doubly_linked_list();
        }
        for(int i=0; i<vector_input.size(); i++){
            append(vector_input.at(i));
        }

    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
        node* current;
        current = original.head;
        head = original.head;

        while(current){
            node* copy = new node(current->get_data());
            copy->next = current->next;
            copy->prev = current->prev;
            current = current->next;
        }
        tail = original.tail;
    }

    doubly_linked_list::~doubly_linked_list() {
        node* temp;
        while(head){
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    int doubly_linked_list::get_data(unsigned position) {
        int value;
        node* current = head;
        for(int i=0; i<position; i++){
            current= current->next;
        }
        value = current->get_data();
        return value;
    }

    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
        std::vector<int> set;
        int value;
        node* current = head;
        if(position_from >=size() || position_to>=size() || position_from > position_to || position_from < 0 || position_to < 0){
            throw "ERROR: invalid positions";
        }

        for(int i=0; i<position_from; i++){
            current= current->next;
        }
        for(int i=position_from; i<=position_to; i++){
            value = current->get_data();
            current= current->next;
            set.push_back(value);
        }
        return set;
    }

    unsigned doubly_linked_list::size() {
        node* current = head;
        unsigned count=0;
        while(current != NULL){
            current = current->next;
            count++;
        }
        return count;
    }

    bool doubly_linked_list::is_empty() {
        if(size() == 0){
            return true;
        }
        return false;

    }

    void doubly_linked_list::append(int input) {
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
            temp->prev = current;
            tail = temp;
        }

    }

    void doubly_linked_list::insert(int input, unsigned int location) {
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
            temp->prev = prev;
            temp->next = current;
            current->prev = temp;
        }

        else { // there is no previous node, temp is at at head
            head = temp;
            head->next = current;
            current->prev = head;
            head->prev = NULL;
        }

    }

    void doubly_linked_list::remove(unsigned location) {
        node *prev=NULL;
        node *current;
        current = head;

        for(int i = 0; i < location; i++) { // iterate to the location of the node you want to delete
            prev = current;
            current = current->next;
        }
        if (prev) { // if a previous node exists
            prev->next = current->next;
            current->next->prev = current->prev;
        }
        if(location>size()){
            throw "ERROR: INPUT INTEGER TOO BIG FOR LIST";
        }
        else if(!prev){
            head = current->next;
            current->next->prev = NULL;
        }
        delete(current);

    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {
        doubly_linked_list split(get_set(position, size()-1));
        for(int i=size()-1; i>=position; i--){
            remove(i);
        }
        return split;
    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {
        doubly_linked_list split(get_set(position_1, position_2));
        for(int i=position_2; i>=position_1; i--){
            remove(i);
        }
        return split;

    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {

        if(position_1 > position_2){    //so position_1 ia always first
            int temp = position_1;
            position_1 = position_2;
            position_2 = temp;
        }

        if(position_1 == position_2){
            throw "ERROR: Cannot swap same position";
        }

        node* A = head;
        for(int i=0; i<position_1; i++) {
            A = A->next;
        }

        node* B = head;
        for(int i=0; i<position_2; i++){
            B = B->next;
        }

        node* Aprev = A->prev;
        node* Anext = A->next;
        node* Bprev = B->prev;
        node* Bnext = B->next;

        if(Anext == B && Aprev != NULL && Bnext != NULL){   //Swapping elements next to each other
            Aprev->next = B;
            B->prev = Aprev;
            B->next = A;
            A->prev = B;
            A->next = Bnext;
            Bnext->prev = A;
        }

        else if(Aprev == NULL && Bnext == NULL){ //when swapping head and tail
            if(size()==2){      //if next to each other
                B->next = A;
                A->prev = B;
                A->next = NULL;
                B->prev = NULL;
                head = B;
                tail = A;
            }
            else {
                A->prev = Bprev;
                A->next = NULL;
                Bprev->next = A;
                B->prev = NULL;
                B->next = Anext;
                Anext->prev = B;
                head = B;
                tail = A;
            }
        }

        else if(Aprev == NULL && Bnext != NULL){    //Swapping head and another element that's not tail

            if(Anext == B){         //If next to each other
                B->next = A;
                A->prev = B;
                A->next = Bnext;
                Bnext->prev = A;
                B->prev = NULL;
                head = B;

            }
            else {
                Anext->prev = B;
                Bprev->next = A;
                Bnext->prev = A;
                A->prev = Bprev;
                B->prev = NULL;
                A->next = Bnext;
                B->next = Anext;
                head = B;
            }
        }

        else if(Aprev != NULL && Bnext == NULL){    //Swapping tail and another element that's not head

            if(Anext == B) {         //if next to each other
                Aprev->next = B;
                B->prev = Aprev;
                B->next = A;
                A->prev = B;
                A->next = NULL;
                tail = A;
            }
            else{
                Aprev->next = B;
                B->prev = Aprev;
                B->next = Anext;
                Anext->prev = B;
                Bprev->next = A;
                A->prev = Bprev;
                A->next = NULL;
                tail = A;
            }
        }

        else {                  //if no edge cases apply
            Aprev->next = B;
            Anext->prev = B;
            Bprev->next = A;
            Bnext->prev = A;
            A->prev = Bprev;
            B->prev = Aprev;
            A->next = Bnext;
            B->next = Anext;
        }
    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {            //TODO:: redo using nodes instead of removing inserting data

        if(location_1_start > location_2_start && location_1_start > location_2_end){
            int tempStart = location_1_start;
            int tempEnd = location_1_end;
            location_1_start = location_2_start;
            location_2_start = tempStart;
            location_1_end = location_2_end;
            location_2_end = tempEnd;
        }

        if(location_1_start > location_1_end){
            int temp = location_1_start;
            location_1_start = location_1_end;
            location_1_end = temp;
        }

        if(location_2_start > location_2_end){
            int temp = location_2_start;
            location_2_start = location_2_end;
            location_2_end = temp;
        }

        if(location_1_end>=location_2_start){
            throw "ERROR: Invalid Entries";
        }

        node* A = head;
        for(int i=0; i<location_1_start; i++){
            A = A->next;
        }
        node* B = A;
        for(int i=location_1_start; i<location_1_end; i++){
            B = B->next;
        }
        node* C = B;
        for(int i=location_1_end; i<location_2_start; i++){
            C = C->next;
        }
        node* D = C;
        for(int i=location_2_start; i<location_2_end; i++){
            D = D->next;
        }

        node* Aprev = A->prev;
        node* Bnext = B->next;
        node* Cprev = C->prev;
        node* Dnext = D->next;

        if(Aprev != NULL && Dnext != NULL && Cprev == B){
            Aprev->next = C;
            C->prev = Aprev;
            D->next = A;
            A->prev = D;
            B->next = Dnext;
            Dnext->prev = B;
        }

        else if(Aprev == NULL && Dnext == NULL){         //If swapping set with head and set with tail

            if(Cprev == B){
                C->prev = NULL;
                D->next = A;
                A->prev = D;
                B->next = NULL;
                head = C;
                tail = B;
            }
            else {
                C->prev = NULL;
                D->next = Bnext;
                Bnext->prev = D;
                Cprev->next = A;
                A->prev = Cprev;
                B->next = NULL;
                head = C;
                tail = B;
            }

        }

        else if(Aprev ==NULL && Dnext != NULL){     //If swapping set with head and another set not including tail
            if(Bnext == C || Cprev == B){                          //If sets are right next to each other
                C->prev = NULL;
                D->next = A;
                A->prev = D;
                B->next = Dnext;
                Dnext->prev = D;
                head = C;
            }
            else {                  //If sets are not next to each other
                C->prev = NULL;
                D->next = Bnext;
                Bnext->prev = D;
                Cprev->next = A;
                A->prev = Cprev;
                B->next = Dnext;
                Dnext->prev = B;
                head = C;
            }
        }

        else if(Aprev != NULL && Dnext == NULL){    //If swapping set with tail and any other set that doesn't include head

            if(Cprev == B){         //If next to each other
                Aprev->next = C;
                C->prev = Aprev;
                D->next = A;
                A->prev = D;
                B->next = NULL;
                tail = B;
            }
            else {
                Aprev->next = C;
                C->prev = Aprev;
                D->next = Bnext;
                Bnext->prev = D;
                Cprev->next = A;
                A->prev = Cprev;
                B->next = NULL;
                tail = B;
            }

        }

        //Generic condition
        else {
            Aprev->next = C;
            C->prev = Aprev;
            D->next = Bnext;
            Bnext->prev = D;
            Cprev->next = A;
            A->prev = Cprev;
            B->next = Dnext;
            Dnext->prev = B;
        }




        /*std::vector<int> setA;
        setA = get_set(location_1_start, location_1_end);
        std::vector<int> setB;
        setB = get_set(location_2_start, location_2_end);

        for(int i = location_2_start; i<location_2_end; i++){
            remove(i);
        }
        for(int i = location_1_start; i<location_1_end; i++){
            remove(i);
        }

        int shift = setB.size()-setA.size();
        for(int i=0; i<setB.size(); i++){
            insert(setA.at(i), location_1_start);
        }
        for(int i=0; i<setA.size(); i++){
            insert(setB.at(i), location_2_start+shift);
        }*/

    }

    void doubly_linked_list::sort() {
        // Implement Insertion Sort
    }

    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {

    }

    doubly_linked_list& doubly_linked_list::operator=(const doubly_linked_list &rhs) {

    }

    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {

    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {

    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {

    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {

    }
}

