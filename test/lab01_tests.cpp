#include "gtest/gtest.h"
#include "expressionstream.h"

class Lab01Fixture : public ::testing::Test {

protected:
    virtual void TearDown() {
        delete stream1;
        delete stream2;
    }

    virtual void SetUp() {
        stream1=new lab1::expressionstream("1+2+3");
        stream2=new lab1::expressionstream("1   + 2 *4+(2*3)");
        stream3=new lab1::expressionstream("-1 +-2");
    }


public:
    lab1::expressionstream *stream1;
    lab1::expressionstream *stream2;
    lab1::expressionstream *stream3;
};


TEST(crashTest , constructorTest) {
    lab1::expressionstream stream1 ("1+2+3");
    lab1::expressionstream stream2 ("1   + 2 *4+(2*3)");
}


TEST_F(Lab01Fixture, basicTest) {
    EXPECT_EQ("1",stream1->get_next_int());
    EXPECT_EQ("2",stream1->get_next_int());
    EXPECT_EQ("3",stream1->get_next_int());

    EXPECT_EQ("+",stream1->get_next_op());
    EXPECT_EQ("+",stream1->get_next_op());
//todo: Get these tests to pass using the debugger
    EXPECT_EQ("1",stream2->get_next_int());
    EXPECT_EQ("2",stream2->get_next_int());
    EXPECT_EQ("4",stream2->get_next_int());
    EXPECT_EQ("2",stream2->get_next_int());
    EXPECT_EQ("3",stream2->get_next_int());

    EXPECT_EQ("+",stream2->get_next_op());
    EXPECT_EQ("*",stream2->get_next_op());
    EXPECT_EQ("+",stream2->get_next_op());
    EXPECT_EQ("(",stream2->get_next_op());
    EXPECT_EQ("*",stream2->get_next_op());
    EXPECT_EQ(")",stream2->get_next_op());

    EXPECT_EQ("+", stream3->get_next_op());
    EXPECT_EQ("-1", stream3->get_next_int());
    EXPECT_EQ("-2", stream3->get_next_int());
}

TEST_F(Lab01Fixture, isNext) {
    EXPECT_FALSE(stream1->expression_complete());
    stream1->get_next_int();
    stream1->get_next_int();
    stream1->get_next_int();
    EXPECT_FALSE(stream1->expression_complete());
    stream1->get_next_op();
    stream1->get_next_op();
    EXPECT_TRUE(stream1->expression_complete());
}


TEST_F(Lab01Fixture, More_Testing) {
    expressionstream stream4("1+2*9");

    EXPECT_EQ("+", stream4.get_next_op());
    EXPECT_EQ("*", stream4.get_next_op());
    EXPECT_EQ("1", stream4.get_next_int());
    EXPECT_EQ("2", stream4.get_next_int());
    EXPECT_EQ("9", stream4.get_next_int());


}

TEST_F(Lab01Fixture, Not_Equal){

    EXPECT_NE("2", stream2->get_next_int());
    EXPECT_NE("1", stream2->get_next_int());
    EXPECT_NE("0", stream2->get_next_int());
    EXPECT_NE("-", stream2->get_next_op());
    EXPECT_NE("+", stream2->get_next_op());


}

TEST_F(Lab01Fixture, IDK){
    EXPECT_FALSE(stream1->expression_complete());
    stream1->get_next_int();
    stream1->get_next_int();
    stream1->get_next_int();
    EXPECT_FALSE(stream1->expression_complete());
    stream1->get_next_op();
    stream1->get_next_op();
    EXPECT_TRUE(stream1->expression_complete());
}

TEST_F(Lab01Fixture, Mix){
    EXPECT_EQ("+", stream3->get_next_op());
    EXPECT_NE("1", stream3->get_next_int());
    EXPECT_NE("2", stream3->get_next_int());
    EXPECT_TRUE(stream3->expression_complete());


}

TEST_F(Lab01Fixture, NEW){
    expressionstream stream5("1+4/9");

    EXPECT_EQ("1", stream5.get_next_int());
    EXPECT_EQ("4", stream5.get_next_int());
    EXPECT_EQ("9", stream5.get_next_int());
    EXPECT_EQ("+", stream5.get_next_op());
    EXPECT_EQ("/", stream5.get_next_op());

}

//todo: create a new test
//step 1: press alt+insert (or right click and select generate)
//step 2: choose test to generate a new test where the cursor is
//step 3: type "Lab01Fixture" in the red box and press tab to go to next auto fill box
//step 4: type name of your test
//step 5: inside the function create your test, use previous test as examples

TEST_F(Lab01Fixture, testTest) {
    lab1::expressionstream stream4("1+2*4");
    EXPECT_NE("2",stream3->get_next_int());
    EXPECT_NE("0",stream3->get_next_int());
}
