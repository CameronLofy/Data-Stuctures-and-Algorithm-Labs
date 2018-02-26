

#include <string>
#include <cstring>
#include "calculator.h"
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {        //TODO:: clean white spaces,
        lab1::expressionstream stream(input_expression);
        


    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        lab3::lifo stack;

        for(int i=0; i<infix_expression.size(); i++){
            int get_number(std::string infix_expression[i]);

        }

        //put everything here regarding queue/stack and auxiliary functions

    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);

    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        return stream;
    }

    int lab4::calculator::calculate() {
        return 0;
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        return stream;
    }


    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string){
        if(input_string == "0"||"1"||"2"||"3"||"4"||"5"||"6"||"7"||"8"||"9"){
            return true;
        }

    }


    bool is_operator(std::string input_string){
        if(input_string == "+"|| "-"|| "*"|| "/"|| "("||")"||"^"){
            return true;
        }


    }

    int get_number(std::string input_string) {
        if(is_number(input_string)){
            lab3::fifo enqueue(input_string);
        }
        else if (is_operator(input_string)){
            lab3::lifo push(input_string);
        }
        else {
            throw"ERROR: NOT OPERATOR OR NUMBER";
        }
    }

    std::string get_operator(std::string input_string){
        lab3::lifo pop(input_string);

    }

    int operator_priority(std::string operator_in){
        int priority;
        if(operator_in == "+"||"-"){
            priority = 1;
        }
        if(operator_in == "*" || "/"){
            priority = 2;
        }
        if(operator_in == "^"){
            priority = 3;
        }
        if(operator_in == "("|| ")"){
            priority = 4;
        }
        return priority;
    }
}