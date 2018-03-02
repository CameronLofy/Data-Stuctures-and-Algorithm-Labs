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
    std::string test = "8/2";
    lab4::calculator obj(test);
    EXPECT_EQ(4, obj.calculate());
}