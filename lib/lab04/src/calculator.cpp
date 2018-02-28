

#include <string>
#include <cstring>
#include "calculator.h"
#include<iostream>
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        lab1::expressionstream stream(input_expression);
        int counter = 0;
        while(counter<input_expression.size()){
            stream.get_next_token();
            infix_expression.enqueue(stream.get_current_token());
            counter++;
        }
    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {      //infix_expression is already a copy, so we ca change it
        lab3::lifo stack;
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string)
        int operator_priority(std::string operator_in);
        std::string current_token;
        while(!infix_expression.is_empty()){
            current_token = infix_expression.top();
            infix_expression.dequeue();
            if(is_number(current_token)){
                postfix_expression.enqueue(current_token);
            }
            if(is_operator(current_token)) {
                while (!stack.is_empty() && operator_priority(current_token) <= operator_priority(stack.top()) && current_token != "(") {
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
                stack.push(current_token);
            }
            if(current_token == "("){
                stack.push(current_token);
            }

            if(current_token == ")"){
                while(stack.top()!="("){
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
            }
        }

        while(!stack.is_empty()){
            postfix_expression.enqueue(current_token);
        }

        /*
        int size = infix_expression.size();
        std::string temp[size];
        for (int i = 0; i < size; i++) {       //copies infix expression into string array
            temp[i] = infix_expression.top();
            infix_expression.dequeue();
        }
        int counter =0;
        lab1::expressionstream post(temp[size]);    //debugger stops here
        post.get_current_token();
        while(counter < size) {
            if (post.next_token_is_int()) {
                postfix_expression.enqueue(temp[counter]);
            }
            if (post.next_token_is_op()) {
                if (stack.is_empty()) {
                    stack.push(temp[counter]);
                }

                else if(operator_priority(stack.top()) >= operator_priority(temp[counter])){
                    while(!stack.is_empty()){
                        postfix_expression.enqueue(stack.top());
                        stack.pop();
                    }
                }

                else if(operator_priority(stack.top()) < operator_priority(temp[counter])){
                    stack.push(temp[counter]);
                }

            }

            if(post.next_token_is_paren_open()){
                stack.push(temp[counter]);
            }

            if(post.next_token_is_paren_close()){
                while(stack.top() != ")") {
                    while (!stack.is_empty()) {
                        std::string tempOP = stack.top();
                        postfix_expression.enqueue(tempOP);
                        stack.pop();
                    }
                }
            }
            post.get_next_token();
            ++counter;
            if(counter>size){
                while(!stack.is_empty()){
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
            }
        }
         */
    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
        calculator::calculate();

    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string input;
        while(stream != eof){
            input.lab3::append(stream);

        }
        RHS.parse_to_infix(input);
        RHS.convert_to_postfix(infix.queue)
        //stream>>input;
        return stream;
    }

    int lab4::calculator::calculate() {
        bool is_operator(std::string input_string);
        int size = postfix_expression.size();
        std::string temp[size];
        lab3::fifo final_calc;
        for (int i = 0; i < size; i++) {
            temp[i] = postfix_expression.top();
            postfix_expression.dequeue();
            if(!is_operator(temp[i])){
                final_calc.enqueue(temp[i]);
            }
            int temp1 = std::stoi(final_calc.top());
            final_calc.dequeue();
            int temp2 = std::stoi(final_calc.top());
            final_calc.dequeue();
            if (temp[i] == "+") {
                return temp1 + temp2;
            } else if (temp[i] == "-") {
                return temp1 - temp2;
            } else if (temp[i] == "*") {
                return temp1 * temp2;
            } else if (temp[i] == "/") {
                return temp1 / temp2;
            }
        }


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
        if(input_string == "+"|| "-"|| "*"|| "/"|| "("||")"){
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
        return priority;
    }
}