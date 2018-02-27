#include "gtest/gtest.h"
#include "expressionstream.h"

class Lab01Fixture : public ::testing::Test {

protected:
    virtual void TearDown() {
        delete stream1;
        delete stream2;
        delete stream3;
        delete stream4;
    }

    virtual void SetUp() {
        stream1=new lab1::expressionstream("1+2+3");
        stream2=new lab1::expressionstream("1   + 2 *4+(2*3)");
        stream3=new lab1::expressionstream("-1 +-2");
        stream4 = new lab1::expressionstream("-1-(-1-(1--1)-1)-1");
    }


public:
    lab1::expressionstream *stream1;
    lab1::expressionstream *stream2;
    lab1::expressionstream *stream3;
    lab1::expressionstream *stream4;
};


TEST(crashTest , constructorTest) {
    lab1::expressionstream stream1("1+2+3");
    lab1::expressionstream stream2("1   + 2 *4+(2*3)");
}

TEST_F(Lab01Fixture, basicNextToken) {
    //1+2+3
    EXPECT_EQ("1", stream1->get_next_token());
    EXPECT_EQ("+", stream1->get_next_token());
    EXPECT_EQ("2", stream1->get_next_token());
    EXPECT_EQ("+", stream1->get_next_token());
    EXPECT_EQ("3", stream1->get_next_token());
    EXPECT_EQ("\0", stream1->get_next_token());

    //1   + 2 *4+(2*3)
    EXPECT_EQ("1", stream2->get_next_token());
    EXPECT_EQ("+", stream2->get_next_token());
    EXPECT_EQ("2", stream2->get_next_token());
    EXPECT_EQ("*", stream2->get_next_token());
    EXPECT_EQ("4", stream2->get_next_token());
    EXPECT_EQ("+", stream2->get_next_token());
    EXPECT_EQ("(", stream2->get_next_token());
    EXPECT_EQ("2", stream2->get_next_token());
    EXPECT_EQ("*", stream2->get_next_token());
    EXPECT_EQ("3", stream2->get_next_token());
    EXPECT_EQ(")", stream2->get_next_token());

    //-1 +-2
    EXPECT_EQ("-1", stream3->get_next_token());
    EXPECT_EQ("+", stream3->get_next_token());
    EXPECT_EQ("-2", stream3->get_next_token());

    //-1-(-1-(1--1)-1)-1
    EXPECT_EQ("-1", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("(", stream4->get_next_token());
    EXPECT_EQ("-1", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("(", stream4->get_next_token());
    EXPECT_EQ("1", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("-1", stream4->get_next_token());
    EXPECT_EQ(")", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("1", stream4->get_next_token());
    EXPECT_EQ(")", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("1", stream4->get_next_token());
}

TEST_F(Lab01Fixture, multiDigitNextToken) {
    delete stream1;
    delete stream2;
    delete stream3;
    delete stream4;

    stream1 = new lab1::expressionstream("123+342+4233");
    stream2 = new lab1::expressionstream("134   + 232 *334+(224*533)");
    stream3 = new lab1::expressionstream("-781 +-2378");
    stream4 = new lab1::expressionstream("-178-(-61-(1--5671)-88671)--13");

    //123+342+4233
    EXPECT_EQ("123", stream1->get_next_token());
    EXPECT_EQ("+", stream1->get_next_token());
    EXPECT_EQ("342", stream1->get_next_token());
    EXPECT_EQ("+", stream1->get_next_token());
    EXPECT_EQ("4233", stream1->get_next_token());
    EXPECT_EQ("\0", stream1->get_next_token());

    //134   + 232 *334+(224*533)
    EXPECT_EQ("134", stream2->get_next_token());
    EXPECT_EQ("+", stream2->get_next_token());
    EXPECT_EQ("232", stream2->get_next_token());
    EXPECT_EQ("*", stream2->get_next_token());
    EXPECT_EQ("334", stream2->get_next_token());
    EXPECT_EQ("+", stream2->get_next_token());
    EXPECT_EQ("(", stream2->get_next_token());
    EXPECT_EQ("224", stream2->get_next_token());
    EXPECT_EQ("*", stream2->get_next_token());
    EXPECT_EQ("533", stream2->get_next_token());
    EXPECT_EQ(")", stream2->get_next_token());

    //-781 +-2378
    EXPECT_EQ("-781", stream3->get_next_token());
    EXPECT_EQ("+", stream3->get_next_token());
    EXPECT_EQ("-2378", stream3->get_next_token());

    //-178-(-61-(1--5671)-88671)--13
    EXPECT_EQ("-178", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("(", stream4->get_next_token());
    EXPECT_EQ("-61", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("(", stream4->get_next_token());
    EXPECT_EQ("1", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("-5671", stream4->get_next_token());
    EXPECT_EQ(")", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("88671", stream4->get_next_token());
    EXPECT_EQ(")", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("-13", stream4->get_next_token());
}

TEST_F(Lab01Fixture, multiDigitCurrentToken) {
    delete stream1;
    delete stream2;
    delete stream3;
    delete stream4;

    stream1 = new lab1::expressionstream("123+342+4233");
    stream2 = new lab1::expressionstream("134   + 232 *334+(224*533)");
    stream3 = new lab1::expressionstream("-781 +-2378");
    stream4 = new lab1::expressionstream("-178-(-61-(1--5671)-88671)--13");

    //123+342+4233
    stream1->get_next_token();
    EXPECT_EQ("123", stream1->get_current_token());
    stream1->get_next_token();
    EXPECT_EQ("+", stream1->get_current_token());
    stream1->get_next_token();
    EXPECT_EQ("342", stream1->get_current_token());
    stream1->get_next_token();
    EXPECT_EQ("+", stream1->get_current_token());
    stream1->get_next_token();
    EXPECT_EQ("4233", stream1->get_current_token());
    stream1->get_next_token();
    EXPECT_EQ("\0", stream1->get_current_token());
    stream1->get_next_token();

    //134   + 232 *334+(224*533)
    stream2->get_next_token();
    EXPECT_EQ("134", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("+", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("232", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("*", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("334", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("+", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("(", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("224", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("*", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("533", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ(")", stream2->get_current_token());
    stream2->get_next_token();

    //-781 +-2378
    stream3->get_next_token();
    EXPECT_EQ("-781", stream3->get_current_token());
    stream3->get_next_token();
    EXPECT_EQ("+", stream3->get_current_token());
    stream3->get_next_token();
    EXPECT_EQ("-2378", stream3->get_current_token());
    stream3->get_next_token();

    //-178-(-61-(1--5671)-88671)--13
    stream4->get_next_token();
    EXPECT_EQ("-178", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("(", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-61", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("(", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("1", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-5671", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ(")", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("88671", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ(")", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-13", stream4->get_current_token());
    stream4->get_next_token();
}

TEST_F(Lab01Fixture, CheckNextType) {
    EXPECT_TRUE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_TRUE(stream1->next_token_is_int());
    stream1->get_next_token();

    EXPECT_TRUE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_TRUE(stream1->next_token_is_op());
    stream1->get_next_token();

    EXPECT_TRUE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_TRUE(stream1->next_token_is_int());
    stream1->get_next_token();

    EXPECT_TRUE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_TRUE(stream1->next_token_is_op());
    stream1->get_next_token();

    EXPECT_TRUE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_TRUE(stream1->next_token_is_int());
    stream1->get_next_token();

    EXPECT_FALSE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_FALSE(stream1->next_token_is_int());

    EXPECT_TRUE(stream2->next_token_is_int());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_op());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_int());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_op());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_int());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_op());
    stream2->get_next_token();

    EXPECT_FALSE(stream2->next_token_is_int());
    EXPECT_FALSE(stream2->next_token_is_op());
    EXPECT_FALSE(stream2->next_token_is_paren_close());
    EXPECT_TRUE(stream2->next_token_is_paren_open());
    EXPECT_FALSE(stream2->next_token_is_int());
    stream2->get_next_token();

    EXPECT_TRUE(stream2->next_token_is_int());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_op());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_int());
    stream2->get_next_token();

    EXPECT_FALSE(stream2->next_token_is_int());
    EXPECT_FALSE(stream2->next_token_is_op());
    EXPECT_TRUE(stream2->next_token_is_paren_close());
    EXPECT_FALSE(stream2->next_token_is_paren_open());
    EXPECT_FALSE(stream2->next_token_is_int());
    stream2->get_next_token();

    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_paren_open());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_paren_open());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_op());
    EXPECT_FALSE(stream4->next_token_is_int());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_paren_close());
    EXPECT_FALSE(stream4->next_token_is_paren_open());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_op());
    EXPECT_FALSE(stream4->next_token_is_int());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_paren_close());
    EXPECT_FALSE(stream4->next_token_is_paren_open());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_op());
    EXPECT_FALSE(stream4->next_token_is_int());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
}