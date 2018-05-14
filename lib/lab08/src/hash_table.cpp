#include "../inc/hash_table.h"

namespace lab8{
    unsigned hash_table::hash_1(std::string to_hash) {
        // DJB2 Hashing Algorithm
        unsigned int hash = 5381;
        for(char c: to_hash){
            hash = ((hash << 5) + hash) + c;
        }
        return hash;
    }

    unsigned hash_table::hash_2(std::string to_hash) {
        // BKDR Hashing Algorithm
        unsigned int seed = 131;
        unsigned int hash = 0;
        for(char c: to_hash){
            hash = (hash * seed) + c;
        }
        return hash;
    }

    void hash_table::expand() {
        int i=0;
        while(PRIMES[i] != max_size){
            i++;
        }
        i++;
        int new_size = PRIMES[i];
        key_value *temp = new key_value[max_size];
        for(int j=0; j<max_size; j++){
            temp[j].key = hash_table_array[j].key;
            temp[j].value = hash_table_array[j].value;
        }
        delete[] hash_table_array;
        hash_table_array = new key_value[new_size];
        for(int k=0; k<new_size; k++){
            hash_table_array[k].key = "\0";
            hash_table_array[k].value = 0;
        }
        for(int i=0; i<max_size; i++){
            if(temp[i].key != "\0"){
                insert(temp[i].key, temp[i].value);
            }
        }
        delete[] temp;
    }

    hash_table::hash_table(char type) {
        if(type == 'q'){
            probing = 'q';
        }
        else if(type == 'd'){
            probing = 'd';
        }
        else{
            probing = 'l';
        }
        current_size = 0;
        max_size = PRIMES[0];
        hash_table_array = new key_value[max_size];
        for(int i=0; i<max_size; i++){
            hash_table_array[i].key = "\0";
            hash_table_array[i].value = 0;
        }
    }

    hash_table::~hash_table() {
        current_size = 0;
        delete[] hash_table_array;
    }

    bool hash_table::insert(std::string key, int value) {
        if(in_table(key) && get(key)==value){
            return true;
        }
        if(current_size >= 0.7*max_size){
            expand();
        }
        int n = hash_1(key);
        if(hash_table_array[n%max_size].key == "\0"){
            hash_table_array[n%max_size].key = key;
            hash_table_array[n%max_size].value = value;
        }
        else{
            if(probing == 'l'){
                while(hash_table_array[n%max_size].key != "\0"){
                    n++;
                }
                hash_table_array[n%max_size].key = key;
                hash_table_array[n%max_size].value = value;
            }
            else if(probing == 'q'){
                int attempt = 1;
                while(hash_table_array[(n + attempt^2)%max_size].key != "\0"){
                    n++;
                }
                hash_table_array[(n + attempt^2)%max_size].key = key;
                hash_table_array[(n + attempt^2)%max_size].value = value;
            }
            else if(probing == 'd'){
                int m = hash_2(key);
                while(hash_table_array[n%max_size].key != "\0"){
                    n++;
                }
                hash_table_array[n%max_size].key = key;
                hash_table_array[n%max_size].value = value;
            }
        }
        // Insert a key according to the defined probing technique
        // If you run into an issue where you get an infinite collision loop,
        //   figure out a way to get out of the loop.
        return true;
    }

    bool hash_table::in_table(std::string key){
        int n = hash_1(key);
        if(hash_table_array[n%max_size].key == key){
            return true;
        }
        if(probing == 'l') {
            int count = 0;
            while (hash_table_array[n % max_size].key != key && count < max_size) {
                n++;
                count++;
            }
            if (hash_table_array[n % max_size].key == key) {
                return true;
            } else {
                return false;
            }
        }

        else if(probing == 'q') {

            int attempt = 1;
            while (hash_table_array[(n + (attempt ^ 2)) % max_size].key != key && attempt<max_size) {
                attempt++;
            }
            if (hash_table_array[(n + (attempt ^ 2)) % max_size].key == key) {
                return true;
            } else {
                return false;
            }
        }
        else {
            int m = hash_2(key);


            int attempt = 1;
            while (hash_table_array[(n + attempt * m) % max_size].key == key && attempt<max_size) {
                attempt++;
            }
            if (hash_table_array[(n + attempt * m) % max_size].key == key) {
                return true;
            } else {
                return false;
            }
        }
        // Checks to see if that key is in the table.
        // Use the specified probing technique
        // Keep collisions in mind
    }

    int hash_table::get(std::string key) {
        int n = hash_1(key);
        if(hash_table_array[n%max_size].key == key){
            return hash_table_array[n%max_size].value;
        }
        if(probing == 'l') {
            int count = 0;
            while (hash_table_array[n % max_size].key != key && count < max_size) {
                n++;
                count++;
            }
            if (hash_table_array[n % max_size].key == key) {
                return hash_table_array[n%max_size].value;
            } else {
                return 0;
            }
        }
        else if(probing == 'q') {
            int attempt = 1;
            while (hash_table_array[(n + (attempt ^ 2)) % max_size].key != key && attempt<max_size) {
                attempt++;
            }
            if (hash_table_array[(n + (attempt ^ 2)) % max_size].key == key) {
                return hash_table_array[(n + (attempt ^ 2)) % max_size].value;
            } else {
                return 0;
            }
        }
        else {
            int m = hash_2(key);
            int attempt = 1;
            while (hash_table_array[(n + attempt * m) % max_size].key == key && attempt<max_size) {
                attempt++;
            }
            if (hash_table_array[(n + attempt * m) % max_size].key == key) {
                return hash_table_array[(n + attempt * m) % max_size].value;
            } else {
                return 0;
            }
        }
        // Get the int value from the node that has key
        // Use the specified probing technique
    }

    void hash_table::update(std::string key, int value){    //Change the value associated with a key. If the value is not in the hash table, insert it.
        if(!in_table(key)){
            insert(key, value);
        }
        else{
            remove(key);
            insert(key, value);
        }
    }

    void hash_table::remove(std::string key){
        int n = hash_1(key);
        if(hash_table_array[n%max_size].key == key){
            hash_table_array[n%max_size].key = "\0";
            hash_table_array[n%max_size].value = 0;
        }
        else {
            if (probing == 'l') {
                int count = 0;
                while (hash_table_array[n % max_size].key != key && count < max_size) {
                    n++;
                    count++;
                }
                if (hash_table_array[n % max_size].key == key) {
                    hash_table_array[n % max_size].key = "\0";
                    hash_table_array[n % max_size].value = 0;
                } else {
                    throw "Not in table";
                }
            } else if (probing == 'q') {

                int attempt = 1;
                while (hash_table_array[(n + (attempt ^ 2)) % max_size].key != key && attempt < max_size) {
                    attempt++;
                }
                if (hash_table_array[(n + (attempt ^ 2)) % max_size].key == key) {
                    hash_table_array[(n + (attempt ^ 2)) % max_size].key = "\0";
                    hash_table_array[(n + (attempt ^ 2)) % max_size].value = 0;
                } else {
                    throw "Not in table";
                }
            } else {
                int m = hash_2(key);


                int attempt = 1;
                while (hash_table_array[(n + attempt * m) % max_size].key == key && attempt < max_size) {
                    attempt++;
                }
                if (hash_table_array[(n + attempt * m) % max_size].key == key) {
                    hash_table_array[(n + attempt * m) % max_size].key = "\0";
                    hash_table_array[(n + attempt * m) % max_size].value = 0;
                } else {
                    throw "Not in table";
                }
            }
        }
    }

    std::string hash_table::to_string(){
        std::string output;
        std::string index;
        std::string v_int;

        for(int i=0; i<max_size; i++){
            index = std::to_string(i);
            v_int = std::to_string(hash_table_array[i].value);
            output += "[" + index +"]" + hash_table_array[i].key + ":" + v_int + " ";
        }
        // Run through the entire array and create a string following this format. The {} brackets aren't part of the return
        // [{array location}]{key_value.key}:{key_value.int}
    return output;
    }
}
