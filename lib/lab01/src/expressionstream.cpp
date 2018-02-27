#include "expressionstream.h"

namespace lab1 {
    bool is_number(char c);
    expressionstream::expressionstream(const std::string &string_in) : buffer(string_in) {
        current_pos = buffer.begin();
        next_position = current_pos;
        skip_white_space();
    }

    void expressionstream::skip_white_space() {
        while (*current_pos == ' ' && current_pos != buffer.end()) ++current_pos;
        while (*next_position == ' ' && next_position != buffer.end()) ++next_position;
    }

    std::string expressionstream::get_number() {
        bool is_negative = false;
        std::string::iterator number_start;

        //check if the number is negative, this is used to skip any white space after '-'
        if (*current_pos == '-') is_negative = true;

        //find beginning of number
        number_start = current_pos;
        while (number_start != buffer.end() && !is_number(*number_start))++number_start;

        //find ending of number
        next_position = number_start;
        while (next_position != buffer.end() && is_number(*next_position))++next_position;

        //create and return number using position iterators
        return (is_negative) ? '-' + std::string(number_start, next_position) : std::string(number_start,
                                                                                            next_position);

    }

    bool expressionstream::is_negative() {
        //after finding a '-' check if it is minus or negative by checking previous character

        //create an iterator to the previous character
        std::string::iterator negative_check = next_position - 1;

        //move backward until reach non-whitespace
        while (negative_check != buffer.begin() && *negative_check == ' ') --negative_check;

        //if the previous character is not a number and not a close parenthesis the number is negative
        //EXAMPLE: the following should get negatives on the 13's but not the 5's : "-13-(-13-(5--13)-5)--13"
        return (!is_number(*negative_check) && *negative_check != ')');
    }

    std::string expressionstream::get_next_token() {
        //move the current_position iterator forward then get the "current" token
        current_pos = next_position;
        return get_current_token();
    }

    std::string expressionstream::get_current_token() {
        skip_white_space();

        //check for end of buffer
        if (current_pos == buffer.end()) return "\0";

        //reset next position each time current token is called
        //this should stop the 'next_position' from drifting on
        //consecutive "get_current_token()" calls
        next_position = current_pos;

        if (next_token_is_int())
            return get_number();

        //if token is not a number then it is one character long
        //setting the 'next_position' iterator forward one will
        //return one character
        ++next_position;
        return std::string(current_pos, next_position);
    }

    bool expressionstream::next_token_is_int() {
        skip_white_space();
        if (is_number(*next_position))
            return true;
        if (*next_position != '-')
            return false;
        return is_negative();
    }

    bool expressionstream::next_token_is_op() {
        skip_white_space();
        if (next_token_is_int()) return false;
        return (*next_position == '+' || *next_position == '-' || *next_position == '*' || *next_position == '/');
    }

    bool expressionstream::next_token_is_paren_open() {
        skip_white_space();
        return *next_position == '(';
    }

    bool expressionstream::next_token_is_paren_close() {
        skip_white_space();
        return *next_position == ')';
    }

    bool is_number(char c) {
        return (c >= '0' && c <= '9');
    }
}