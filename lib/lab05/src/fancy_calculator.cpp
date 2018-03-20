#include "fancy_calculator.h"
#include "stack.h"
#include "queue.h"

namespace lab5{
    void calculator::parse_to_infix(std::string &input_expression) {
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);

        int size = 0;
        int op = 0;
        int infix_size = 0;

        std::string temp[input_expression.size()];
        for(std::string::iterator it = input_expression.begin(); it != input_expression.end(); ++it) {
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
                if(op != size) {
                    while (op != size && is_number(temp[op])) {      //finds position of operator
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

    void calculator::convert_to_postfix(lab5::queue infix_expression) {
        lab5::stack stack;
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        int operator_priority(std::string operator_in);

        std::string current_token;
        while (!infix_expression.isEmpty()) {
            current_token = infix_expression.top();
            infix_expression.dequeue();

            if (is_number(current_token)){
                postfix_expression.enqueue(current_token);
            }

            if (is_operator(current_token)){
                while (!stack.isEmpty() && operator_priority(current_token) <= operator_priority(stack.top()) &&
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
                if(stack.isEmpty()){
                    throw (std::string("ERROR: INVALID ARGUMENT"));
                }
                while (stack.top() != "(") {

                    postfix_expression.enqueue(stack.top());
                    stack.pop();

                    if(stack.isEmpty()){
                        throw (std::string("ERROR: INVALID ARGUMENT"));
                    }


                }
                stack.pop();
            }
        }

        while (!stack.isEmpty()) {     //puts everything left from stack to queue
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

    int calculator::calculate() {
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        int final;

        lab5::stack calc_stack;
        lab5::queue postfixCopy;
        postfixCopy = postfix_expression;
        while(!postfixCopy.isEmpty()){
            if(is_number(postfixCopy.top())) {
                calc_stack.push(postfixCopy.top());
                postfixCopy.dequeue();
            }

            else if(is_operator(postfixCopy.top())){
                std::string tempOP = postfixCopy.top();
                postfixCopy.dequeue();
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

                if(tempOP == "^"){
                    int z = 1;
                    if(x==0){
                        std::string calc = std::to_string(z);
                    }
                    else {
                        for (int i = 1; i <= x; i++) {
                            z *= y;
                        }
                        final = z;
                        std::string calc = std::to_string(final);
                        calc_stack.push(calc);
                    }
                }

                if(tempOP == "%"){
                    final = y%x;
                    std::string calc = std::to_string(final);
                    calc_stack.push(calc);
                }

            }
        }
        int final_calc = std::stoi(calc_stack.top());
        return final_calc;
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        int infix_size = RHS.infix_expression.queueSize();
        int postfix_size = RHS.postfix_expression.queueSize();

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
            if(input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/" || input_string == "(" || input_string == ")" || input_string == "%") {
                return false;
            }
            return true;
        }
        return false;
    }

    bool is_operator(std::string input_string){
        if(input_string == "+"||input_string == "-"||input_string == "*"||input_string == "/"||input_string == "^"||input_string == "%"){
            return true;
        }
        return false;
    }

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    int operator_priority(std::string operator_in){
        int priority;
        if(operator_in == "+"|| operator_in == "-"){
            priority = 1;
        }
        if(operator_in == "*" || operator_in == "/" || operator_in == "%"){
            priority = 2;
        }
        if(operator_in == "^"){
            priority = 3;
        }
        return priority;
    }

}

