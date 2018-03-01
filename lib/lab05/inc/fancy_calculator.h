#ifndef CMPE126S18_LABS_LAB5_CALCULATOR_H
#define CMPE126S18_LABS_LAB5_CALCULATOR_H

#include "stack.h"
#include "queue.h"
#include "expressionstream.h"
#include <iostream>

namespace lab5{
    class calculator{
        lab5::queue infix_expression;
        lab5::queue postfix_expression;

        void parse_to_infix(std::string &input_expression); //PRIVATE function used for converting input string into infix notation
        void convert_to_postfix(lab5::queue infix_expression); //PRIVATE function used for converting infix FIFO to postfix
    public:
        calculator();   //Default constructor
        calculator(std::string &input_expression); // Constructor that converts input_expression to infix and postfix upon creation
        friend std::istream& operator>>(std::istream& stream, calculator& RHS); //Store the infix and postfix expression in calculator

        int calculate(); //Return the calculation of the postfix expression
        friend std::ostream& operator<<(std::ostream& stream, calculator& RHS); //Stream out overload. Should return in the format "Infix: #,#,#,#\nPostfix: #,#,#,#"
    };
}

#endif