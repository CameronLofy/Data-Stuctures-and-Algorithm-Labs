#include "gtest/gtest.h"
#include "lifo.h"
#include "fifo.h"
#include "calculator.h"



class Lab04Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

public:
};

TEST_F(Lab04Fixture, build_test){
    std::string test = "4+2+5+8";
    lab4::calculator obj(test);
    EXPECT_EQ(19, obj.calculate());
}

TEST_F(Lab04Fixture, complex_eq){
    std::string test = "2-(3*4/6)+4";
    lab4::calculator obj(test);
    EXPECT_EQ(4, obj.calculate());
}

TEST_F(Lab04Fixture, complex_eq2){
    std::string test = "7*3+(4/2-1)-2";
    lab4::calculator obj(test);
    EXPECT_EQ(20, obj.calculate());
}

TEST_F(Lab04Fixture, complex_eq3){
    std::string test = "2+16+4";
    lab4::calculator obj(test);
    EXPECT_EQ(22, obj.calculate());
}

TEST_F(Lab04Fixture, complex_eq4){
    std::string test = "(420/10+8-4)/2";
    lab4::calculator obj(test);
    EXPECT_EQ(23, obj.calculate());
}

TEST_F(Lab04Fixture, division){
    std::string test = "999/9";
    lab4::calculator obj(test);
    EXPECT_EQ(111, obj.calculate());
}

TEST_F(Lab04Fixture, multiplication){
    std::string test = "2*16*4";
    lab4::calculator obj(test);
    EXPECT_EQ(128, obj.calculate());
}

TEST_F(Lab04Fixture, subtraction){
    std::string test = "24-8-4+2-3";
    lab4::calculator obj(test);
    EXPECT_EQ(11, obj.calculate());
}

TEST_F(Lab04Fixture, addition){
    std::string test = "1+15+4+20";
    lab4::calculator obj(test);
    EXPECT_EQ(40, obj.calculate());
}

TEST_F(Lab04Fixture, parentheses){
    std::string test = "(4-2)*5";
    lab4::calculator obj(test);
    EXPECT_EQ(10, obj.calculate());
}

TEST_F(Lab04Fixture, parentheses2){
    std::string test = "5*(4-2)";
    lab4::calculator obj(test);
    EXPECT_EQ(10, obj.calculate());
}

TEST_F(Lab04Fixture, parentheses3){
    std::string test = "5*(4-2)-(6-2)";
    lab4::calculator obj(test);
    EXPECT_EQ(6, obj.calculate());
}

TEST_F(Lab04Fixture, doubleInt_parentheses){
    std::string test = "10*(42-20)";
    lab4::calculator obj(test);
    EXPECT_EQ(220, obj.calculate());
}

TEST_F(Lab04Fixture, doubleInt_parentheses2){
    std::string test = "(42-20)*5";
    lab4::calculator obj(test);
    EXPECT_EQ(110, obj.calculate());
}

TEST_F(Lab04Fixture, doubleInt_parentheses3){
    std::string test = "(42-20)*10";
    lab4::calculator obj(test);
    EXPECT_EQ(220, obj.calculate());
}

TEST_F(Lab04Fixture, doubleInt_parentheses4){
    std::string test = "(42-20)*((22/2)-6)";
    lab4::calculator obj(test);
    EXPECT_EQ(110, obj.calculate());
}

TEST_F(Lab04Fixture, doubleInt_parentheses5){
    std::string test = "(((4*2)+10)/9)-(12/3-3)";
    lab4::calculator obj(test);
    EXPECT_EQ(1, obj.calculate());
}