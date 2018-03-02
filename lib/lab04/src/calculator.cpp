

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
        bool is_operator(std::string input_string);
        int operator_priority(std::string operator_in);
        std::string current_token;
        while (!infix_expression.is_empty()) {
            current_token = infix_expression.top();
            infix_expression.dequeue();
            if(infix_expression.is_empty()) {
                while (!stack.is_empty()) {
                    std::string temp = stack.top();
                    stack.pop();
                    postfix_expression.enqueue(temp);
                }
            }
            if (is_number(current_token) == true){
                postfix_expression.enqueue(current_token);
            }
            if (is_operator(current_token)){
                while (!stack.is_empty() && operator_priority(current_token) <= operator_priority(stack.top()) &&
                       current_token != "(") {
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
            }
        }

        while (!stack.is_empty()) {
            postfix_expression.enqueue(current_token);
            stack.pop();
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

    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
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
                    final = x+y;
                    std::string calc = std::to_string(final);
                    calc_stack.push(calc);

        }




            }
        }
        return 0;


        /*
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
         */
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {

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