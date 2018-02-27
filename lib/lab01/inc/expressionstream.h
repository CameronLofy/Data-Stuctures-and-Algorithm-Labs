#ifndef CMPE126S18_LABS_STSTRING_H
#define CMPE126S18_LABS_STSTRING_H


#include <string>

namespace lab1 {
    class expressionstream {
    private:
        std::string buffer;
        std::string::iterator current_pos;
        std::string::iterator next_position;

        void skip_white_space();

        std::string get_number();

        bool is_negative();
    public:
        explicit expressionstream(const std::string &string_in);

        std::string get_next_token();

        std::string get_current_token();

        bool next_token_is_int();

        bool next_token_is_op();

        bool next_token_is_paren_open();

        bool next_token_is_paren_close();
    };
}
#endif //CMPE126S18_LABS_STSTRING_H
