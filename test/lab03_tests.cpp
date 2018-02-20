#include "gtest/gtest.h"
#include "fifo.h"
#include "lifo.h"


class Lab03Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        testVec = new lab3::fifo;
        testVec->enqueue("Test 1");
        testVec->enqueue("Test 2");
        testVec->enqueue("Test 3");
        testVec->enqueue("Test 4");
        testVec->enqueue("Test 5");

        lifotest = new lab3::lifo;
        lifotest->push("Test 1");
        lifotest->push("Test 2");
        lifotest->push("Test 3");
        lifotest->push("Test 4");
        lifotest->push("Test 5");
    }

    virtual void TearDown() {
    }

public:
    lab3::fifo * testVec;
    lab3::lifo * lifotest;
};

//FIFO TESTS

TEST_F(Lab03Fixture, fifo_constructor){
       lab3::fifo ct;
    EXPECT_TRUE(ct.is_empty());
    EXPECT_EQ(0, ct.size());

}

TEST_F(Lab03Fixture, fifo_ExplicitConstructor){
    lab3::fifo ict("Test 1");
    EXPECT_EQ(1, ict.size());
    EXPECT_EQ("Test 1", ict.top());
    ict.enqueue("Test 2");
    ict.dequeue();
    EXPECT_EQ("Test 2", ict.top());

}


TEST_F(Lab03Fixture, fifo_CopyConstructor){
    lab3::fifo* copy = testVec;
    EXPECT_EQ("Test 1",copy->top());
    copy->dequeue();
    EXPECT_EQ("Test 2",copy->top());
    delete copy;
}


TEST_F(Lab03Fixture, Top){
    EXPECT_EQ("Test 1", testVec->top());
    EXPECT_EQ(5, testVec->size());
    testVec->dequeue();
    EXPECT_EQ("Test 2", testVec->top());
    EXPECT_EQ(4, testVec->size());
    testVec->dequeue();
    testVec->dequeue();
    EXPECT_EQ("Test 4", testVec->top());
    EXPECT_EQ(2, testVec->size());
}


//LIFO TESTS

TEST_F(Lab03Fixture, lifo_construtor){
    lab3::lifo lc;
    EXPECT_EQ(0, lc.size());
    EXPECT_TRUE(lc.is_empty());

}

TEST_F(Lab03Fixture, lifo_ExplicitConstructor){
    lab3::lifo lec("Test 1");
    EXPECT_EQ("Test 1", lec.top());

}

TEST_F(Lab03Fixture, lifo_CopyConstructor){
    lab3::lifo* copy = lifotest;
    EXPECT_EQ("Test 5", copy->top());
}

TEST_F(Lab03Fixture, lifo_Push){
    lifotest->push("Test 6");
    lifotest->push("Test 7");
    EXPECT_EQ("Test 7", lifotest->top());
    lifotest->pop();
    EXPECT_EQ("Test 6", lifotest->top());
}