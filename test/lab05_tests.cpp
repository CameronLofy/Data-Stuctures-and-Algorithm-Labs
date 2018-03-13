#include "gtest/gtest.h"
#include "queue.h"
#include "stack.h"
#include "fancy_calculator.h"

class Lab05Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

public:
};

TEST_F(Lab05Fixture, Queue_1){
    lab5::queue q1;
    q1.enqueue("1");
    EXPECT_EQ("1", q1.top());
    q1.enqueue("2");
    EXPECT_EQ(2, q1.queueSize());
    EXPECT_EQ("1", q1.top());
    q1.dequeue();
    EXPECT_EQ("2", q1.top());
    EXPECT_EQ(1, q1.queueSize());
    q1.dequeue();
    EXPECT_EQ(0, q1.queueSize());
    EXPECT_TRUE(q1.isEmpty());
}

TEST_F(Lab05Fixture, Queue_2){
    std::string Test= "Test";
    lab5::queue q1(Test);
    q1.enqueue("Hello");
    EXPECT_EQ("Test", q1.top());
    q1.enqueue("World");
    EXPECT_EQ(3, q1.queueSize());
    EXPECT_EQ("Test", q1.top());
    q1.dequeue();
    EXPECT_EQ("Hello", q1.top());
    EXPECT_EQ(2, q1.queueSize());
    q1.dequeue();
    EXPECT_EQ(1, q1.queueSize());

    EXPECT_EQ("World", q1.top());
    q1.dequeue();
    EXPECT_TRUE(q1.isEmpty());
}

TEST_F(Lab05Fixture, Sort){
    lab5::linked_list list_1;
    EXPECT_TRUE(list_1.isEmpty());
    list_1.append("7");
    list_1.append("6");
    list_1.append("2");
    list_1.append("4");
    list_1.append("3");
    list_1.append("5");
    list_1.append("1");
    EXPECT_EQ("7", list_1.get_value_at(0));
    EXPECT_EQ("6", list_1.get_value_at(1));
    EXPECT_EQ("2", list_1.get_value_at(2));
    EXPECT_EQ("4", list_1.get_value_at(3));
    EXPECT_EQ("3", list_1.get_value_at(4));
    EXPECT_EQ("5", list_1.get_value_at(5));
    EXPECT_EQ("1", list_1.get_value_at(6));
    list_1.sort();
    EXPECT_EQ("1", list_1.get_value_at(0));
    EXPECT_EQ("2", list_1.get_value_at(1));
    EXPECT_EQ("3", list_1.get_value_at(2));
    EXPECT_EQ("4", list_1.get_value_at(3));
    EXPECT_EQ("5", list_1.get_value_at(4));
    EXPECT_EQ("6", list_1.get_value_at(5));
    EXPECT_EQ("7", list_1.get_value_at(6));
}

TEST_F(Lab05Fixture, Sort_2){
    lab5::linked_list list_1;
    EXPECT_TRUE(list_1.isEmpty());
    list_1.append("7");
    list_1.append("6");

    EXPECT_EQ("7", list_1.get_value_at(0));
    EXPECT_EQ("6", list_1.get_value_at(1));

    list_1.sort();
    EXPECT_EQ("6", list_1.get_value_at(0));
    EXPECT_EQ("7", list_1.get_value_at(1));

}