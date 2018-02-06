#ifndef CMPE126S18_LABS_STSTRING_H
#define CMPE126S18_LABS_STSTRING_H


#include <string>

class expressionstream {
private:
    std::string buffer;
    std::string next_int;
    std::string next_op;
    std::string::iterator pos_next;
    std::string::iterator pos_next_int;
    std::string::iterator pos_next_op;
    bool is_first_int;

    void update_pos_next();
    void find_next_int();
    void find_next_op();
    void align_next_int();
    void align_next_op();

public:
    explicit expressionstream(const std::string &string_in);

    std::string str() const;
    void str (const std::string& s);

    bool expression_complete();

    std::string get_next_int();
    std::string get_next_op();
};


#endif //CMPE126S18_LABS_STSTRING_H
