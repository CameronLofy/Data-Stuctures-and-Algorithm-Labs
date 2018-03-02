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
    std::string test = "16+4";
    lab4::calculator obj(test);
    EXPECT_EQ(20, obj.calculate());
}