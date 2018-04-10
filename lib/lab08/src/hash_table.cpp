#include "../inc/hash_table.h"

namespace lab8{
    unsigned hash_table::hash(std::string to_hash) {
        return 0;
    }

    void hash_table::expand() {

    }

    hash_table::hash_table() {

    }

    hash_table::~hash_table() {

    }

    void hash_table::insert(std::string key, int value) {
        // Insert a key
    }

    bool hash_table::in_table(std::string key){
        // Checks to see if that keey is in the table. Keep collisions in mind
    }

    int hash_table::get(std::string key) {
        // Get the int value from the node that has key
        return 0;
    }

    void hash_table::update(std::string key, int value){
        // Update a key in the hashtable. Keep collisions in mind
    }

    void hash_table::remove(std::string key){
        //Remove an item from the hash table. Keep collisions in mind
    }

    std::string hash_table::to_string(){
        // Run through the entire array and create a string following this format. The {} brackets aren't part of the return
        // [{array location}]{key_value.key}:{key_value.int}
    }
}
