

#include <string>
#include <cstring>
#include "calculator.h"
#include<iostream>
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);

        int size = 0;
        int op = 0;
        int infix_size = 0;

        std::string temp[input_expression.size()];
        for(std::string::iterator it = input_expression.begin(); it != input_expression.end(); ++it) {
            //do_things_with(*it);
            temp[size] = *it;
            size++;
        }


        for(int i=0; i<size; i++){

            if(temp[i] == " "){      //skips blank spaces
                i++;
            }

            else if(i==size-1){     //if last number, otherwise crashes when checking for temp[i+1]
                infix_expression.enqueue(temp[i]);
                infix_size++;
            }

            if(i!=size-1 && !is_number(temp[i])){
                infix_expression.enqueue(temp[i]);
                infix_size++;
            }

            if(i!=size-1 && is_number(temp[i]) && !is_number(temp[i+1]) ){  //if only one digit, queues it right away
                infix_expression.enqueue(temp[i]);
                infix_size++;
            }

            if(i!=size-1 && is_number(temp[i]) && is_number(temp[i+1])){    //if multidigit number
                op=i;
                if(op == size-2){
                    op=op+2;
                }
                if(op == size-3){
                    op=op+3;
                }
                if(op != size) {
                    while (op != size - 1 && is_number(temp[op])) {      //finds position of operator
                        op++;
                    }
                }
                std::string int_temp;
                for(int z=i; z < op; z++){
                    int_temp += temp[i++];      //puts values of temp[i] into string int_temp until it reached the operator
                }
                i = op-1;
                infix_expression.enqueue(int_temp);
                infix_size++;
            }
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

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string input;
        while(stream.peek() != EOF){
            input = stream.get();
        }
        RHS.parse_to_infix(input);
        RHS.convert_to_postfix(RHS.infix_expression);
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

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        int infix_size = RHS.infix_expression.size();
        int postfix_size = RHS.postfix_expression.size();

        stream << std::string("Infix Expression: ");
        for (int i = 0; i < infix_size; i++) {
            stream << RHS.infix_expression.top();
            RHS.infix_expression.dequeue();
        }
        stream << "\n";

        stream << std::string("Postfix Expression: ");
        for (int i = 0; i < postfix_size; i++) {
            stream << RHS.postfix_expression.top();
            RHS.postfix_expression.dequeue();
        }
        stream << "\n";
        return stream;
    }


    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string){
        if(input_string >= "0" && input_string <= "999"){
            if(input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/" || input_string == "(" || input_string == ")") {
                return false;
            }
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
            throw "ERROR: NOT OPERATOR OR NUMBER";
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