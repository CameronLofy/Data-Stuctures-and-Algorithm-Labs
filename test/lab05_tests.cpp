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
    lab5::queue q2;
    q2 = q1;
    EXPECT_EQ("Test", q2.top());
    lab5::queue q3(q1);
    EXPECT_EQ("Test", q3.top());
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

TEST_F(Lab05Fixture, Stack){
    lab5::stack S1;
    EXPECT_TRUE(S1.isEmpty());
    std::string a = "hello";
    std::string b = "world";
    S1.push(a);
    EXPECT_EQ("hello", S1.top());
    S1.push(b);
    EXPECT_EQ("world",S1.top());
    EXPECT_EQ(2,S1.queueSize());
    lab5::stack S2;
    S2 = S1;
    EXPECT_EQ("world", S2.top());
    EXPECT_EQ(2,S1.queueSize());
    S1.pop();
    S2.pop();
    EXPECT_EQ("hello",S1.top());
    EXPECT_EQ("hello",S1.top());
}

TEST_F(Lab05Fixture, Calculator){
    std::string test1 = "3^2";
    lab5::calculator calc(test1);
    EXPECT_EQ(9, calc.calculate());
}

TEST_F(Lab05Fixture, TripleInt_parentheses){
    std::string test = "(((400*2)/16)+500)/11";
    lab5::calculator obj(test);
    EXPECT_EQ(50, obj.calculate());
}

TEST_F(Lab05Fixture, build_test){
    std::string test = "4+2+5+8";
    lab5::calculator obj(test);
    EXPECT_EQ(19, obj.calculate());
}

TEST_F(Lab05Fixture, Fancy_parentheses){
    std::string test = "(((4^2)/8)+2)";
    lab5::calculator obj(test);
    EXPECT_EQ(4, obj.calculate());
}

TEST_F(Lab05Fixture, Fancy_Modulo){
    std::string test = "15%2";
    lab5::calculator obj(test);
    EXPECT_EQ(1, obj.calculate());
}

TEST_F(Lab05Fixture, Fancy_Modulo_2){
    std::string test = "(((40%19)*5)^2)/25";
    lab5::calculator obj(test);
    EXPECT_EQ(4, obj.calculate());
}

TEST_F(Lab05Fixture, Fancy_Modulo_3){
    std::string test = "((((40%19)*5)^2)/25)";
    lab5::calculator obj(test);
    EXPECT_EQ(4, obj.calculate());
}

TEST_F(Lab05Fixture, complicated2){
    std::string a = "10-(2^3)";
    lab5::calculator C(a);
    EXPECT_EQ(2,C.calculate());
}

TEST_F(Lab05Fixture, Fancy_Modulo_Paren){
    std::string test = "(150%10)";
    lab5::calculator obj(test);
    EXPECT_EQ(0, obj.calculate());
}

TEST_F(Lab05Fixture, Fancy_As_Fuck){
    std::string test = "(425%7)*(3^3)-(1+12*(10%7))";
    lab5::calculator obj(test);
    EXPECT_EQ(98, obj.calculate());
}

TEST_F(Lab05Fixture, complicated){
    std::string a = "2-(3*4/6)+4";
    lab5::calculator C(a);
    EXPECT_EQ(4,C.calculate());
}

