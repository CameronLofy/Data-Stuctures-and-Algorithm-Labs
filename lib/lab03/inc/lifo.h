#ifndef CMPE126S18_LABS_STACK_H
#define CMPE126S18_LABS_STACK_H
#include "stringVector.h"

namespace lab3 {
    class lifo {
        lab2::stringVector lifo_storage;
        unsigned index;
    public:
        lifo();                                          //Default constructor. Reserve 100 spaces in lifo_storage
        explicit lifo(std::string input_string);        //Create new lifo from string input
        lifo(const lifo &original);                     //Copy constructor
        virtual ~lifo();                                //Destructor
        lifo &operator=(const lifo &right);            //Assignment operator

        bool is_empty();  // Return true if the lifo is empty and false if it is not
        int size();  // Return the size of the lifo

        std::string top();        // Return the top of the lifo.
        void push(std::string input);   // Add input string to the top of the string
        void pop();                     // Remove the top string from the lifo
    };
}

#endif
