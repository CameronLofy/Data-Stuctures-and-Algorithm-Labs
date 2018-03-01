#include "fancy_calculator.h"
#include "stack.h"
#include "queue.h"

namespace lab5{
    void calculator::parse_to_infix(std::string &input_expression) {

    }

    void calculator::convert_to_postfix(lab5::queue infix_expression) {

    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {

    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        return stream;
    }

    int calculator::calculate() {
        return 0;
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        return stream;
    }


    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string);

    bool is_operator(std::string input_string);

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    int operator_priority(std::string operator_in);

}

