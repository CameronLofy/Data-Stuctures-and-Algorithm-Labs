#include "gtest/gtest.h"
#include "calculator.h"
#include <sstream>

class Lab04Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        calculator_UT=new lab4::calculator;
    }

    virtual void TearDown() {
        delete calculator_UT;
    }

public:
    lab4::calculator* calculator_UT;
    std::string input;
};

TEST(crash_test,crash_test_calculator_Test){
    lab4::calculator *calc_underTest=new lab4::calculator;
    delete calc_underTest;
    std::string input("1 + 2");
    calc_underTest=new lab4::calculator(input);
    delete calc_underTest;
}


TEST_F(Lab04Fixture, calc_calculator_simple_test) {
    delete calculator_UT;
    input = "1 + 2 + 3 - 3 - 2 - 1";
    calculator_UT = new lab4::calculator(input);

    EXPECT_EQ(0,calculator_UT->calculate());

    delete calculator_UT;
    input = "1 * 2 * 3 / 3 / 2 / 1";
    calculator_UT = new lab4::calculator(input);

    EXPECT_EQ(1,calculator_UT->calculate());

    delete calculator_UT;
    input = "2 * 3 + 5 - 1";
    calculator_UT = new lab4::calculator(input);

    EXPECT_EQ(10,calculator_UT->calculate());

    delete calculator_UT;
    input = "11 + 22 + 33 - 33 - 22 - 11";
    calculator_UT = new lab4::calculator(input);

    EXPECT_EQ(0,calculator_UT->calculate());

    delete calculator_UT;
    input = "11 * 22 * 33 / 33 / 22 / 11";
    calculator_UT = new lab4::calculator(input);

    EXPECT_EQ(1,calculator_UT->calculate());

    delete calculator_UT;
    input = "2 * 30 + 54 - 1";
    calculator_UT = new lab4::calculator(input);

    EXPECT_EQ(113,calculator_UT->calculate());
}

TEST_F(Lab04Fixture, calc_calculator_test) {
    delete calculator_UT;
    input = "271 + 32 * ( 91 - 1 ) + 14 / 2";
    calculator_UT = new lab4::calculator(input);

    EXPECT_EQ(3158,calculator_UT->calculate());

    delete calculator_UT;
    input = "49 * ( 17 * ( 3 + 2 * ( 12 + 2 * ( 45 - 43 ) + 2 ) ) + 1 * ( 6 / 2 ) )";
    calculator_UT = new lab4::calculator(input);

    EXPECT_EQ(32634,calculator_UT->calculate());

    delete calculator_UT;
    input = "( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 )";
    calculator_UT = new lab4::calculator(input);

    EXPECT_EQ(20,calculator_UT->calculate());
}


TEST_F(Lab04Fixture, calculator_istream_ostream_test) {
    std::stringstream* stream;

    delete(calculator_UT);
    input = "1 + 2 + 3";
    calculator_UT=new lab4::calculator(input);

    testing::internal::CaptureStdout();
    std::cout << *calculator_UT;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("Infix: 1,+,2,+,3\nPostfix: 1,2,+,3,+",output);

    stream = new std::stringstream(input);
    *stream >> *calculator_UT;

    testing::internal::CaptureStdout();
    std::cout << *calculator_UT;
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("Infix: 1,+,2,+,3\nPostfix: 1,2,+,3,+",output);

    delete(calculator_UT);
    input = "49 * ( 17 * ( 3 + 2 * ( 12 + 2 * ( 45 - 43 ) + 2 ) ) + 1 * ( 6 / 2 ) )";
    calculator_UT=new lab4::calculator(input);

    testing::internal::CaptureStdout();
    std::cout << *calculator_UT;
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("Infix: 49,*,(,17,*,(,3,+,2,*,(,12,+,2,*,(,45,-,43,),+,2,),),+,1,*,(,6,/,2,),)\nPostfix: 49,17,3,2,12,2,45,43,-,*,+,2,+,*,+,*,1,6,2,/,*,+,*",output);

    stream = new std::stringstream(input);
    *stream >> *calculator_UT;

    testing::internal::CaptureStdout();
    std::cout << *calculator_UT;
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("Infix: 49,*,(,17,*,(,3,+,2,*,(,12,+,2,*,(,45,-,43,),+,2,),),+,1,*,(,6,/,2,),)\nPostfix: 49,17,3,2,12,2,45,43,-,*,+,2,+,*,+,*,1,6,2,/,*,+,*",output);
}