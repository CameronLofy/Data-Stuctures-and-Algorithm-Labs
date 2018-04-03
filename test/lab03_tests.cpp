#include "gtest/gtest.h"
#include "fifo.h"
#include "lifo.h"

class Lab03Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        FIFO_underTest = new lab3::fifo;
        LIFO_underTest = new lab3::lifo;
    }

    virtual void TearDown() {
        delete(FIFO_underTest);
        delete(LIFO_underTest);
    }

public:
    lab3::fifo *FIFO_underTest;
    lab3::lifo *LIFO_underTest;
};

TEST(crash_test,crash_test_fifo_Test){
    lab3::fifo *fifo_UT=new lab3::fifo;
    delete fifo_UT;
}

TEST(crash_test,crash_test_lifo_Test){
    lab3::lifo *lifo_UT=new lab3::lifo;
    delete lifo_UT;
}

TEST_F(Lab03Fixture, fifo_input_con_top_test){
    delete(FIFO_underTest);
    FIFO_underTest = new lab3::fifo("test string");
    EXPECT_EQ("test string",FIFO_underTest->top());
}

TEST_F(Lab03Fixture, lifo_input_con_top_test){
    delete(LIFO_underTest);
    LIFO_underTest = new lab3::lifo("test string");
    EXPECT_EQ("test string",LIFO_underTest->top());
}

TEST_F(Lab03Fixture, fifo_enqueue_dequeue_top_test){
    FIFO_underTest->enqueue("test string");
    EXPECT_EQ("test string",FIFO_underTest->top());

    FIFO_underTest->enqueue("test string1");
    EXPECT_EQ("test string",FIFO_underTest->top());

    FIFO_underTest->enqueue("test string2");
    EXPECT_EQ("test string",FIFO_underTest->top());

    FIFO_underTest->enqueue("test string3");
    EXPECT_EQ("test string",FIFO_underTest->top());

    FIFO_underTest->dequeue();
    EXPECT_EQ("test string1",FIFO_underTest->top());

    FIFO_underTest->dequeue();
    EXPECT_EQ("test string2",FIFO_underTest->top());

    FIFO_underTest->dequeue();
    EXPECT_EQ("test string3",FIFO_underTest->top());

    FIFO_underTest->dequeue();
}

TEST_F(Lab03Fixture, lifo_push_pop_top_test){
    LIFO_underTest->push("test string");
    EXPECT_EQ("test string",LIFO_underTest->top());

    LIFO_underTest->push("test string1");
    EXPECT_EQ("test string1",LIFO_underTest->top());

    LIFO_underTest->push("test string2");
    EXPECT_EQ("test string2",LIFO_underTest->top());

    LIFO_underTest->push("test string3");
    EXPECT_EQ("test string3",LIFO_underTest->top());

    LIFO_underTest->pop();
    EXPECT_EQ("test string2",LIFO_underTest->top());

    LIFO_underTest->pop();
    EXPECT_EQ("test string1",LIFO_underTest->top());

    LIFO_underTest->pop();
    EXPECT_EQ("test string",LIFO_underTest->top());

    LIFO_underTest->pop();
}


TEST_F(Lab03Fixture, fifo_size_isEmpty_test) {
    EXPECT_TRUE(FIFO_underTest->is_empty());
    EXPECT_EQ(0,FIFO_underTest->size());

    FIFO_underTest->enqueue("test string");
    EXPECT_EQ(1,FIFO_underTest->size());
    EXPECT_FALSE(FIFO_underTest->is_empty());

    FIFO_underTest->enqueue("test string1");
    EXPECT_EQ(2,FIFO_underTest->size());
    EXPECT_FALSE(FIFO_underTest->is_empty());

    FIFO_underTest->enqueue("test string2");
    EXPECT_EQ(3,FIFO_underTest->size());
    EXPECT_FALSE(FIFO_underTest->is_empty());

    FIFO_underTest->enqueue("test string3");
    EXPECT_EQ(4,FIFO_underTest->size());
    EXPECT_FALSE(FIFO_underTest->is_empty());

    FIFO_underTest->dequeue();
    EXPECT_EQ(3,FIFO_underTest->size());
    EXPECT_FALSE(FIFO_underTest->is_empty());

    FIFO_underTest->dequeue();
    EXPECT_EQ(2,FIFO_underTest->size());
    EXPECT_FALSE(FIFO_underTest->is_empty());

    FIFO_underTest->dequeue();
    EXPECT_EQ(1,FIFO_underTest->size());
    EXPECT_FALSE(FIFO_underTest->is_empty());

    FIFO_underTest->dequeue();

    EXPECT_EQ(0,FIFO_underTest->size());
    EXPECT_TRUE(FIFO_underTest->is_empty());
}

TEST_F(Lab03Fixture, lifo_size_isEmpty_test) {
    EXPECT_TRUE(LIFO_underTest->is_empty());
    EXPECT_EQ(0,LIFO_underTest->size());

    LIFO_underTest->push("test string");
    EXPECT_EQ(1,LIFO_underTest->size());
    EXPECT_FALSE(LIFO_underTest->is_empty());

    LIFO_underTest->push("test string1");
    EXPECT_EQ(2,LIFO_underTest->size());
    EXPECT_FALSE(LIFO_underTest->is_empty());

    LIFO_underTest->push("test string2");
    EXPECT_EQ(3,LIFO_underTest->size());
    EXPECT_FALSE(LIFO_underTest->is_empty());

    LIFO_underTest->push("test string3");
    EXPECT_EQ(4,LIFO_underTest->size());
    EXPECT_FALSE(LIFO_underTest->is_empty());

    LIFO_underTest->pop();
    EXPECT_EQ(3,LIFO_underTest->size());
    EXPECT_FALSE(LIFO_underTest->is_empty());

    LIFO_underTest->pop();
    EXPECT_EQ(2,LIFO_underTest->size());
    EXPECT_FALSE(LIFO_underTest->is_empty());

    LIFO_underTest->pop();
    EXPECT_EQ(1,LIFO_underTest->size());
    EXPECT_FALSE(LIFO_underTest->is_empty());

    LIFO_underTest->pop();

    EXPECT_EQ(0,LIFO_underTest->size());
    EXPECT_TRUE(LIFO_underTest->is_empty());
}

TEST_F(Lab03Fixture, fifo_opEq_test){
    auto * FIFO_underTest_copy = new lab3::fifo;
    FIFO_underTest->enqueue("test string");
    FIFO_underTest->enqueue("test string1");
    FIFO_underTest->enqueue("test string2");
    FIFO_underTest->enqueue("test string3");

    FIFO_underTest_copy->operator=(*FIFO_underTest);

    FIFO_underTest->dequeue();
    EXPECT_EQ("test string1",FIFO_underTest->top());
    EXPECT_EQ("test string", FIFO_underTest_copy->top());
    FIFO_underTest_copy->dequeue();

    FIFO_underTest->dequeue();
    EXPECT_EQ("test string2",FIFO_underTest->top());
    EXPECT_EQ("test string1", FIFO_underTest_copy->top());
    FIFO_underTest_copy->dequeue();

    FIFO_underTest->dequeue();
    EXPECT_EQ("test string3",FIFO_underTest->top());
    EXPECT_EQ("test string2", FIFO_underTest_copy->top());
    FIFO_underTest_copy->dequeue();
    EXPECT_EQ("test string3", FIFO_underTest_copy->top());

    FIFO_underTest->dequeue();
    FIFO_underTest_copy->dequeue();
}

TEST_F(Lab03Fixture, lifo_opEq_test) {
    auto LIFO_underTest_copy = new lab3::lifo;

    LIFO_underTest->push("test string");
    LIFO_underTest->push("test string1");
    LIFO_underTest->push("test string2");
    LIFO_underTest->push("test string3");

    LIFO_underTest_copy->operator=(*LIFO_underTest);

    LIFO_underTest->pop();
    EXPECT_EQ("test string2", LIFO_underTest->top());
    EXPECT_EQ("test string3", LIFO_underTest_copy->top());
    LIFO_underTest_copy->pop();

    LIFO_underTest->pop();
    EXPECT_EQ("test string1", LIFO_underTest->top());
    EXPECT_EQ("test string2", LIFO_underTest_copy->top());
    LIFO_underTest_copy->pop();

    LIFO_underTest->pop();
    EXPECT_EQ("test string", LIFO_underTest->top());
    EXPECT_EQ("test string1", LIFO_underTest_copy->top());
    LIFO_underTest_copy->pop();
    EXPECT_EQ("test string", LIFO_underTest_copy->top());

    LIFO_underTest->pop();
    LIFO_underTest_copy->pop();
}

TEST_F(Lab03Fixture, Fifo_loopback_test) {
    lab3::fifo fifo_UT;
    fifo_UT.enqueue("test Input");
    for (int i = 0; i < 150; ++i) {
        ASSERT_NO_THROW(fifo_UT.enqueue("test Input")) << "failed on iteration: " << i << "\n";
        ASSERT_EQ("test Input", fifo_UT.top()) << "failed on iteration: " << i << "\n";
        ASSERT_NO_THROW(fifo_UT.enqueue("test Input")) << "failed on iteration: " << i << "\n";
        ASSERT_EQ("test Input", fifo_UT.top()) << "failed on iteration: " << i << "\n";
        ASSERT_NO_THROW(fifo_UT.enqueue("test Input")) << "failed on iteration: " << i << "\n";
        ASSERT_EQ("test Input", fifo_UT.top()) << "failed on iteration: " << i << "\n";

        ASSERT_EQ(4, fifo_UT.size()) << "failed on iteration: " << i << "\n";
        ASSERT_FALSE(fifo_UT.is_empty()) << "failed on iteration: " << i << "\n";

        ASSERT_EQ("test Input", fifo_UT.top()) << "failed on iteration: " << i << "\n";
        ASSERT_NO_THROW(fifo_UT.dequeue()) << "failed on iteration: " << i << "\n";
        ASSERT_EQ("test Input", fifo_UT.top()) << "failed on iteration: " << i << "\n";
        ASSERT_NO_THROW(fifo_UT.dequeue()) << "failed on iteration: " << i << "\n";
        ASSERT_EQ("test Input", fifo_UT.top()) << "failed on iteration: " << i << "\n";
        ASSERT_NO_THROW(fifo_UT.dequeue()) << "failed on iteration: " << i << "\n";

        ASSERT_EQ(1, fifo_UT.size()) << "failed on iteration: " << i << "\n";
        ASSERT_FALSE(fifo_UT.is_empty()) << "failed on iteration: " << i << "\n";
    }
    ASSERT_EQ("test Input", fifo_UT.top());
    ASSERT_NO_THROW(fifo_UT.dequeue());
}