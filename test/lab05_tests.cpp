#include "gtest/gtest.h"
#include "queue.h"
#include "stack.h"
#include "fancy_calculator.h"
#include <algorithm>

class Lab05Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        list_UT = new lab5::linked_list ;
        calculator_UT = new lab5::calculator ;
        stack_UT = new lab5::stack ;
        queue_UT = new lab5::queue ;
    }

    virtual void TearDown() {
        delete list_UT;
        delete calculator_UT;
        delete stack_UT;
        delete queue_UT;
    }

public:
    lab5::linked_list  * list_UT;
    lab5::calculator  * calculator_UT;
    lab5::stack  * stack_UT;
    lab5::queue  * queue_UT;
    std::string input;
};

TEST(crashTest , lab5_constructor_destructor_Test) {
    auto list_underTest = new lab5::linked_list;
    auto calc_underTest = new lab5::calculator;
    auto stack_underTest = new lab5::stack;
    auto queue_underTest = new lab5::queue;

    delete list_underTest;
    delete calc_underTest;
    delete stack_underTest;
    delete queue_underTest;

    std::string input = "1 + 2";
    list_underTest = new lab5::linked_list(input);
    calc_underTest = new lab5::calculator(input);
    stack_underTest = new lab5::stack(input);
    queue_underTest = new lab5::queue(input);

    delete list_underTest;
    delete calc_underTest;
    delete stack_underTest;
    delete queue_underTest;
}

/***** linked list tests *****/



TEST_F(Lab05Fixture, linked_insert_test) {//make sure valid insertions run without crashing
    input = "test string";
    for(int i =0; i< 200; i++) { // insert at the beginning
        EXPECT_NO_THROW(list_UT->insert(input)) << "failed on iteration: " << i << "\n";
    }
    for(int i =0; i < 300; i+=2){ // insert in the middle
        EXPECT_NO_THROW(list_UT->insert(input,i)) << "failed on iteration: " << i << "\n";
    }
}


TEST_F(Lab05Fixture, linked_append_test) {//make sure valid appends run without crashing
    input = "test string";
    for(int i=0; i<200; ++i) EXPECT_NO_THROW(list_UT->append(input)) << "failed on iteration: " << i << "\n";
}


TEST_F(Lab05Fixture, linked_insert_append_value_check) {
    for(int i=0; i<200; ++i) {
        input = "test string " + std::to_string(i+1);
        EXPECT_NO_THROW(list_UT->insert(input)) << "failed on iteration: " << i << "\n";
        EXPECT_EQ(input, list_UT->get_value_at(0)) << "failed on iteration: " << i << "\n";
    }
    for(int i=0; i<300; i+=2){
        input = "test string " + std::to_string(2*i+1);
        EXPECT_NO_THROW(list_UT->insert(input,i));
        EXPECT_EQ(input, list_UT->get_value_at(i));
    }
    for (int i = 0; i < 100; ++i) {
        input = "test string" + std::to_string(i*3);
        EXPECT_NO_THROW(list_UT->append(input));
        EXPECT_EQ(input,list_UT->get_value_at(list_UT->listSize()-1));
    }
}


TEST_F(Lab05Fixture, linked_opEq_insert_append_value_test) {
    auto list_UT_copy = new lab5::linked_list;

    for(int i=0; i<200; ++i) {
        input = "test string " + std::to_string(i+1);
        EXPECT_NO_THROW(list_UT->insert(input)) << "failed on iteration: " << i << "\n";
        EXPECT_EQ(input, list_UT->get_value_at(0)) << "failed on iteration: " << i << "\n";
    }
    list_UT_copy->operator=(*list_UT);
    EXPECT_EQ(list_UT_copy->listSize(),list_UT->listSize());

    for (int i = 0; i < 200; ++i) {//ensure full copy
        input = "test string " + std::to_string(200-i);
        EXPECT_EQ(input, list_UT_copy->get_value_at(i)) << "failed on iteration: " << i << "\n";
    }

    for(int i=0; i<300; i+=2) {//alter copy
        input = "test string " + std::to_string(2 * i + 1);
        EXPECT_NO_THROW(list_UT_copy->insert(input, i)) << "failed on iteration: " << i << "\n";
    }

    for (int i = 0; i < 200; ++i) {//check values of original after altering copy to ensure mutual exclusive nodes
        input = "test string " + std::to_string(200-i);
        EXPECT_EQ(input, list_UT->get_value_at(i)) << "failed on iteration: " << i << "\n";
    }
}

TEST_F(Lab05Fixture, linked_copy_insert_append_value_test) {
    for(int i=0; i<200; ++i) {
        input = "test string " + std::to_string(i+1);
        EXPECT_NO_THROW(list_UT->insert(input)) << "failed on iteration: " << i << "\n";
        EXPECT_EQ(input, list_UT->get_value_at(0)) << "failed on iteration: " << i << "\n";
    }
    auto list_UT_copy = new lab5::linked_list(*list_UT);
    EXPECT_EQ(list_UT_copy->listSize(),list_UT->listSize());

    for (int i = 0; i < 200; ++i) {//ensure full copy
        input = "test string " + std::to_string(200-i);
        EXPECT_EQ(input, list_UT_copy->get_value_at(i)) << "failed on iteration: " << i << "\n";
    }

    for(int i=0; i<300; i+=2) {//alter copy
        input = "test string " + std::to_string(2 * i + 1);
        EXPECT_NO_THROW(list_UT_copy->insert(input, i)) << "failed on iteration: " << i << "\n";
    }

    for (int i = 0; i < 200; ++i) {//check values of original after altering copy to ensure mutual exclusive nodes
        input = "test string " + std::to_string(200-i);
        EXPECT_EQ(input, list_UT->get_value_at(i)) << "failed on iteration: " << i << "\n";
    }
}

TEST_F(Lab05Fixture, linked_insert_remove_value_empty_size_test) {
    EXPECT_TRUE(list_UT->isEmpty());
    for(int i=0; i<200; ++i) {
        input = "test string " + std::to_string(i+1);
        EXPECT_NO_THROW(list_UT->insert(input)) << "failed on iteration: " << i << "\n";
        EXPECT_EQ(input, list_UT->get_value_at(0)) << "failed on iteration: " << i << "\n";
        EXPECT_FALSE(list_UT->isEmpty());
    }

    for (int i = 0; i < 200; ++i) {//check values of original after altering copy to ensure mutual exclusive nodes
        input = "test string " + std::to_string(200-i);
        EXPECT_EQ(input, list_UT->get_value_at(0)) << "failed on iteration: " << i << "\n";
        EXPECT_NO_THROW(list_UT->remove())<< "failed on iteration: " << i << "\n";
        EXPECT_EQ(199-i, list_UT->listSize())<< "failed on iteration: " << i << "\n";
        if(i == 199)EXPECT_TRUE(list_UT->isEmpty())<< "failed on iteration: " << i << "\n";
        else EXPECT_FALSE(list_UT->isEmpty())<< "failed on iteration: " << i << "\n";
    }

    for(int i=0; i<200; ++i) {
        input = "test string " + std::to_string(i+1);
        EXPECT_NO_THROW(list_UT->insert(input)) << "failed on iteration: " << i << "\n";
        EXPECT_EQ(input, list_UT->get_value_at(0)) << "failed on iteration: " << i << "\n";
        EXPECT_FALSE(list_UT->isEmpty())<< "failed on iteration: " << i << "\n";
    }

    for(int i=0; i<100; ++i) {//remove every other item
        EXPECT_NO_THROW(list_UT->remove(i))<< "failed on iteration: " << i << "\n";
        EXPECT_FALSE(list_UT->isEmpty())<< "failed on iteration: " << i << "\n";
    }

    for(int i =0; i<100; ++i){
        input = "test string " + std::to_string((200-2*i)-1);
        EXPECT_EQ(input, list_UT->get_value_at(i))<< "failed on iteration: " << i << "\n";
    }
}


TEST_F(Lab05Fixture, linked_insert_remove_size_test) {
    for(int i =0; i < 200; ++i){
        input = "test data";
        EXPECT_EQ(i,list_UT->listSize())<< "failed on iteration: " << i << "\n";
        EXPECT_NO_THROW(list_UT->insert(input))<< "failed on iteration: " << i << "\n";
    }
    for (int i = 0; i < 200; ++i) {
        EXPECT_EQ(200-i, list_UT->listSize())<< "failed on iteration: " << i << "\n";
        EXPECT_NO_THROW(list_UT->remove())<< "failed on iteration: " << i << "\n";
    }
}


TEST_F(Lab05Fixture, linked_ostream_istream_test) {
    std::string expected_output;
    input = "testing";
    std::stringstream stream(input);

    stream >> *list_UT;
    EXPECT_EQ(input,list_UT->get_value_at(0));
    expected_output = input + " -> ";

    for(int i =0; i < 200; ++i){
        input = "test data " + std::to_string(i);
        expected_output = input + " -> " + expected_output;
        EXPECT_NO_THROW(list_UT->insert(input))<< "failed on iteration: " << i << "\n";
    }
    expected_output += "NULL";

    testing::internal::CaptureStdout();
    std::cout << *list_UT;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected_output,output);
}


TEST_F(Lab05Fixture, linked_insert_sort) {
    auto container1 = new std::vector<std::string>;
    container1->reserve(30);

    container1->emplace_back("yellow");
    container1->emplace_back("glad");
    container1->emplace_back("castackrnia");
    container1->emplace_back("question");
    container1->emplace_back("bear");
    container1->emplace_back("restful");
    container1->emplace_back("extra");
    container1->emplace_back("nugget");
    container1->emplace_back("door");
    container1->emplace_back("vehicle");
    container1->emplace_back("full");
    container1->emplace_back("know");
    container1->emplace_back("later");
    container1->emplace_back("apple");
    container1->emplace_back("true");
    container1->emplace_back("joker");
    container1->emplace_back("xeon");
    container1->emplace_back("welcome");
    container1->emplace_back("mannequin");
    container1->emplace_back("oriented");
    container1->emplace_back("programming");
    container1->emplace_back("hello");
    container1->emplace_back("sleep");
    container1->emplace_back("igloo");
    container1->emplace_back("object");
    container1->emplace_back("under");
    container1->emplace_back("fail");

    for (int i = 0; i < container1->size(); ++i) {
        list_UT->insert((*container1)[i]);
    }
    std::sort(container1->begin(), container1->end());
    list_UT->sort();
    for (int j = 0; j < container1->size(); ++j) {
        EXPECT_EQ((*container1)[j], list_UT->get_value_at(j)) << "failed on iteration: " << j << "\n";
    }
}

/***** end link list tests *****/

/***** stack tests *****/
TEST_F(Lab05Fixture, stack_input_con_top_test){
    delete(stack_UT);
    input = "test string";
    stack_UT = new lab5::stack(input);
    EXPECT_EQ("test string",stack_UT->top());
}

TEST_F(Lab05Fixture, stack_push_pop_top_test){
    stack_UT->push("test string");
    EXPECT_EQ("test string",stack_UT->top());

    stack_UT->push("test string1");
    EXPECT_EQ("test string1",stack_UT->top());

    stack_UT->push("test string2");
    EXPECT_EQ("test string2",stack_UT->top());

    stack_UT->push("test string3");
    EXPECT_EQ("test string3",stack_UT->top());

    stack_UT->pop();
    EXPECT_EQ("test string2",stack_UT->top());

    stack_UT->pop();
    EXPECT_EQ("test string1",stack_UT->top());

    stack_UT->pop();
    EXPECT_EQ("test string",stack_UT->top());

    stack_UT->pop();
}

TEST_F(Lab05Fixture, stack_size_isEmpty_test) {
    EXPECT_TRUE(stack_UT->isEmpty());
    EXPECT_EQ(0,stack_UT->stackSize());

    stack_UT->push("test string");
    EXPECT_EQ(1,stack_UT->stackSize());
    EXPECT_FALSE(stack_UT->isEmpty());

    stack_UT->push("test string1");
    EXPECT_EQ(2,stack_UT->stackSize());
    EXPECT_FALSE(stack_UT->isEmpty());

    stack_UT->push("test string2");
    EXPECT_EQ(3,stack_UT->stackSize());
    EXPECT_FALSE(stack_UT->isEmpty());

    stack_UT->push("test string3");
    EXPECT_EQ(4,stack_UT->stackSize());
    EXPECT_FALSE(stack_UT->isEmpty());

    stack_UT->pop();
    EXPECT_EQ(3,stack_UT->stackSize());
    EXPECT_FALSE(stack_UT->isEmpty());

    stack_UT->pop();
    EXPECT_EQ(2,stack_UT->stackSize());
    EXPECT_FALSE(stack_UT->isEmpty());

    stack_UT->pop();
    EXPECT_EQ(1,stack_UT->stackSize());
    EXPECT_FALSE(stack_UT->isEmpty());

    stack_UT->pop();

    EXPECT_EQ(0,stack_UT->stackSize());
    EXPECT_TRUE(stack_UT->isEmpty());
}

TEST_F(Lab05Fixture, stack_opEq_test) {
    auto stack_UT_copy = new lab5::stack;

    stack_UT->push("test string");
    stack_UT->push("test string1");
    stack_UT->push("test string2");
    stack_UT->push("test string3");

    stack_UT_copy->operator=(*stack_UT);

    stack_UT->pop();
    EXPECT_EQ("test string2", stack_UT->top());
    EXPECT_EQ("test string3", stack_UT_copy->top());
    stack_UT_copy->pop();

    stack_UT->pop();
    EXPECT_EQ("test string1", stack_UT->top());
    EXPECT_EQ("test string2", stack_UT_copy->top());
    stack_UT_copy->pop();

    stack_UT->pop();
    EXPECT_EQ("test string", stack_UT->top());
    EXPECT_EQ("test string1", stack_UT_copy->top());
    stack_UT_copy->pop();
    EXPECT_EQ("test string", stack_UT_copy->top());

    stack_UT->pop();
    stack_UT_copy->pop();
}
/***** end stack tests*****/

/***** queue tests *****/
TEST_F(Lab05Fixture, queue_input_con_top_test){
    delete(queue_UT);
    input = "test string";
    queue_UT = new lab5::queue(input);
    EXPECT_EQ("test string",queue_UT->top());
}

TEST_F(Lab05Fixture, queue_enqueue_dequeue_top_test){
    queue_UT->enqueue("test string");
    EXPECT_EQ("test string",queue_UT->top());

    queue_UT->enqueue("test string1");
    EXPECT_EQ("test string",queue_UT->top());

    queue_UT->enqueue("test string2");
    EXPECT_EQ("test string",queue_UT->top());

    queue_UT->enqueue("test string3");
    EXPECT_EQ("test string",queue_UT->top());

    queue_UT->dequeue();
    EXPECT_EQ("test string1",queue_UT->top());

    queue_UT->dequeue();
    EXPECT_EQ("test string2",queue_UT->top());

    queue_UT->dequeue();
    EXPECT_EQ("test string3",queue_UT->top());

    queue_UT->dequeue();
}

TEST_F(Lab05Fixture, queue_size_isEmpty_test) {
    EXPECT_TRUE(queue_UT->isEmpty());
    EXPECT_EQ(0,queue_UT->queueSize());

    queue_UT->enqueue("test string");
    EXPECT_EQ(1,queue_UT->queueSize());
    EXPECT_FALSE(queue_UT->isEmpty());

    queue_UT->enqueue("test string1");
    EXPECT_EQ(2,queue_UT->queueSize());
    EXPECT_FALSE(queue_UT->isEmpty());

    queue_UT->enqueue("test string2");
    EXPECT_EQ(3,queue_UT->queueSize());
    EXPECT_FALSE(queue_UT->isEmpty());

    queue_UT->enqueue("test string3");
    EXPECT_EQ(4,queue_UT->queueSize());
    EXPECT_FALSE(queue_UT->isEmpty());

    queue_UT->dequeue();
    EXPECT_EQ(3,queue_UT->queueSize());
    EXPECT_FALSE(queue_UT->isEmpty());

    queue_UT->dequeue();
    EXPECT_EQ(2,queue_UT->queueSize());
    EXPECT_FALSE(queue_UT->isEmpty());

    queue_UT->dequeue();
    EXPECT_EQ(1,queue_UT->queueSize());
    EXPECT_FALSE(queue_UT->isEmpty());

    queue_UT->dequeue();

    EXPECT_EQ(0,queue_UT->queueSize());
    EXPECT_TRUE(queue_UT->isEmpty());
}

TEST_F(Lab05Fixture, queue_opEq_test){
    auto * queue_UT_copy = new lab5::queue;
    queue_UT->enqueue("test string");
    queue_UT->enqueue("test string1");
    queue_UT->enqueue("test string2");
    queue_UT->enqueue("test string3");

    queue_UT_copy->operator=(*queue_UT);

    queue_UT->dequeue();
    EXPECT_EQ("test string1",queue_UT->top());
    EXPECT_EQ("test string", queue_UT_copy->top());
    queue_UT_copy->dequeue();

    queue_UT->dequeue();
    EXPECT_EQ("test string2",queue_UT->top());
    EXPECT_EQ("test string1", queue_UT_copy->top());
    queue_UT_copy->dequeue();

    queue_UT->dequeue();
    EXPECT_EQ("test string3",queue_UT->top());
    EXPECT_EQ("test string2", queue_UT_copy->top());
    queue_UT_copy->dequeue();
    EXPECT_EQ("test string3", queue_UT_copy->top());

    queue_UT->dequeue();
    queue_UT_copy->dequeue();
}
/***** end queue tests*****/

/***** calculator tests *****/

TEST_F(Lab05Fixture, fancy_calc_calculator_simple_test) {
    delete calculator_UT;
    input = "1 + 2 + 3 - 3 - 2 - 1";
    calculator_UT = new lab5::calculator(input);

    EXPECT_EQ(0,calculator_UT->calculate());

    delete calculator_UT;
    input = "1 * 2 * 3 / 3 / 2 / 1";
    calculator_UT = new lab5::calculator(input);

    EXPECT_EQ(1,calculator_UT->calculate());

    delete calculator_UT;
    input = "2 * 3 + 5 - 1";
    calculator_UT = new lab5::calculator(input);

    EXPECT_EQ(10,calculator_UT->calculate());

    delete calculator_UT;
    input = "11 + 22 + 33 - 33 - 22 - 11";
    calculator_UT = new lab5::calculator(input);

    EXPECT_EQ(0,calculator_UT->calculate());

    delete calculator_UT;
    input = "11 * 22 * 33 / 33 / 22 / 11";
    calculator_UT = new lab5::calculator(input);

    EXPECT_EQ(1,calculator_UT->calculate());

    delete calculator_UT;
    input = "2 * 30 + 54 - 1";
    calculator_UT = new lab5::calculator(input);

    EXPECT_EQ(113,calculator_UT->calculate());
}

TEST_F(Lab05Fixture, fancy_calc_calculator_test) {
    delete calculator_UT;
    input = "271 + 32 * ( 91 - 1 ) + 14 / 2";
    calculator_UT = new lab5::calculator(input);

    EXPECT_EQ(3158,calculator_UT->calculate());

    delete calculator_UT;
    input = "49 * ( 17 * ( 3 + 2 * ( 12 + 2 * ( 45 - 43 ) + 2 ) ) + 1 * ( 6 / 2 ) )";
    calculator_UT = new lab5::calculator(input);

    EXPECT_EQ(32634,calculator_UT->calculate());

    delete calculator_UT;
    input = "( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 )";
    calculator_UT = new lab5::calculator(input);

    EXPECT_EQ(20,calculator_UT->calculate());
}


TEST_F(Lab05Fixture, fancy_calculator_istream_ostream_test) {
    std::stringstream* stream;

    delete(calculator_UT);
    input = "1 + 2 + 3";
    calculator_UT=new lab5::calculator(input);

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
    calculator_UT=new lab5::calculator(input);

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

/***** end calculator tests*****/


