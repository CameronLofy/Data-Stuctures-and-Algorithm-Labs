#ifndef CMPE126S18_LABS_HASH_TABLE_H
#define CMPE126S18_LABS_HASH_TABLE_H

#include <string>
#include <vector>
namespace lab8{

    struct key_value{
        std::string key;
        int value;
    };

    class hash_table{
        key_value *hash_table_array;
        char probing;
        unsigned max_size;
        unsigned current_size;

        const int PRIMES[16] = {31, 67, 137, 277, 557, 1117, 2237, 4481, 8963, 17929, 35863, 71741, 143483, 286999, 574003, 1148029}; // PRIME[n+1]= next prime after 2*PRIME[n]. Use this for setting max size


        unsigned hash_1(std::string to_hash);
        unsigned hash_2(std::string to_hash);
        void expand();

    public:
        hash_table(char type);
        ~hash_table();

        bool insert(std::string key, int value);
        int get(std::string key);
        void remove(std::string key);
        bool in_table(std::string);
        void update(std::string key, int value);

        // Functions use for testings
        unsigned get_size(){ return current_size; };
        unsigned get_max_size(){ return max_size; };
        std::string to_string(); //Used for testing
    };
}

#endif //CMPE126S18_LABS_HASH_TABLE_H
