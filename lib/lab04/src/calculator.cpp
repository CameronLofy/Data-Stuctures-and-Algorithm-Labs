

#include <string>
#include <cstring>
#include "calculator.h"
#include<iostream>
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {        //TODO:: edit to handle multiple digit integers
        lab1::expressionstream stream(input_expression);
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        int counter = 0;
        while(counter<input_expression.size()){
            stream.get_next_token();

            infix_expression.enqueue(stream.get_current_token());
            counter++;
        }
    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {      //infix_expression is already a copy, so we can change it
        lab3::lifo stack;
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        int operator_priority(std::string operator_in);
        std::string current_token;
        while (!infix_expression.is_empty()) {
            current_token = infix_expression.top();
            infix_expression.dequeue();

            if (is_number(current_token)){
                postfix_expression.enqueue(current_token);
            }

            if (is_operator(current_token)){
                while (!stack.is_empty() && operator_priority(current_token) <= operator_priority(stack.top()) &&
                       stack.top() != "(") {
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
                stack.push(current_token);
            }
            if (current_token == "(") {
                stack.push(current_token);
            }

            if (current_token == ")") {
                while (stack.top() != "(") {
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
        }

        while (!stack.is_empty()) {     //puts everything left from stack to queue
            if(stack.top()=="(") {      //skips the '(' within the stack
                stack.pop();
            }
            postfix_expression.enqueue(stack.top());
            stack.pop();
        }
    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);

    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {       //TODO:: something with this
        std::string input;
        while(stream.peek() != EOF){


        }
        RHS.parse_to_infix(input);
        RHS.convert_to_postfix(RHS.infix_expression);
        //stream>>input;
        return stream;
    }

    int lab4::calculator::calculate() {
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        int final;

        lab3::lifo calc_stack;
        while(!postfix_expression.is_empty()){
            if(is_number(postfix_expression.top())) {
                calc_stack.push(postfix_expression.top());
                postfix_expression.dequeue();
            }

            else if(is_operator(postfix_expression.top())){
                std::string tempOP = postfix_expression.top();
                postfix_expression.dequeue();
                int x = std::stoi(calc_stack.top());
                calc_stack.pop();
                int y = std::stoi(calc_stack.top());
                calc_stack.pop();

                if(tempOP == "+"){
                    final = y+x;
                    std::string calc = std::to_string(final);
                    calc_stack.push(calc);
                }

                if(tempOP == "-"){
                    final = y-x;
                    std::string calc = std::to_string(final);
                    calc_stack.push(calc);
                }

                if(tempOP == "*"){
                    final = y*x;
                    std::string calc = std::to_string(final);
                    calc_stack.push(calc);
                }

                if(tempOP == "/"){
                    final = y/x;
                    std::string calc = std::to_string(final);
                    calc_stack.push(calc);
                }

            }
        }
        int final_calc = std::stoi(calc_stack.top());
        return final_calc;

    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {       //TODO:: do something else here

        return stream;
    }


    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string){
        if(input_string =="0"||input_string =="1"||input_string =="2"||input_string =="3"||input_string =="4"||input_string =="5"||input_string =="6"||input_string =="7"||input_string =="8"||input_string =="9"){
            return true;
        }
        return false;

    }


    bool is_operator(std::string input_string){
        if(input_string == "+"||input_string == "-"||input_string == "*"||input_string == "/"){
            return true;
        }
        return false;


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
        return priority;
    }
}