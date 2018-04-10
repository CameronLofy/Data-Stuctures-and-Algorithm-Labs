#ifndef CMPE126S18_LABS_HASH_TABLE_H
#define CMPE126S18_LABS_HASH_TABLE_H

#include <string>
namespace lab8{

    struct key_value{
        std::string key;
        int value;
    };

    class hash_table{
        key_value hash_table_array[];
        unsigned max_size;
        unsigned current_size;

        unsigned hash(std::string to_hash);
        void expand();

    public:
        hash_table();
        ~hash_table();

        void insert(std::string key, int value);
        int get(std::string key);
        void remove(std::string key);
        bool in_table(std::string);
        void update(std::string key, int value);
        std::string to_string(); //Used for testing
    };
}

#endif //CMPE126S18_LABS_HASH_TABLE_H
