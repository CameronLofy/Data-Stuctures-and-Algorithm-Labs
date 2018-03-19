#include "gtest/gtest.h"
#include "doubly_linked_list.h"

class Lab06Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        test1 = new lab6::doubly_linked_list(0);
        test1->append(1);
        test1->append(2);
        test1->append(3);
        test1->append(4);
        test1->append(5);
        test1->append(6);
        test1->append(7);
        test1->append(8);
        test1->append(9);
        test1->append(10);
        test1->append(11);
        test1->append(12);
        test1->append(13);
        test1->append(14);
        test1->append(15);
        test1->append(16);

        test2 = new lab6::doubly_linked_list(5);
        test2->append(8);
        test2->append(2);
        test2->append(4);
        test2->append(1);
        test2->append(3);
        test2->append(7);
        test2->append(6);
        test2->append(0);
    }

    virtual void TearDown() {
        delete test1;
        delete test2;
    }

public:
    lab6::doubly_linked_list *test1;
    lab6::doubly_linked_list *test2;
};

TEST_F(Lab06Fixture, Constructor){
    EXPECT_EQ(0, test1->get_data(0));
    EXPECT_EQ(1, test1->get_data(1));
}

TEST_F(Lab06Fixture, swap){
    test1->swap(3,4);
    EXPECT_EQ(4, test1->get_data(3));
    EXPECT_EQ(3, test1->get_data(4));
    test1->swap(6,9);
    EXPECT_EQ(9, test1->get_data(6));
    EXPECT_EQ(6, test1->get_data(9));
    test1->swap(8,7);
    EXPECT_EQ(8, test1->get_data(7));
    EXPECT_EQ(7, test1->get_data(8));
    test1->swap(12,5);
    EXPECT_EQ(12, test1->get_data(5));
    EXPECT_EQ(5, test1->get_data(12));
}

TEST_F(Lab06Fixture, swap_head){
    test1->swap(0,6);
    EXPECT_EQ(6, test1->get_data(0));
    EXPECT_EQ(0, test1->get_data(6));
    test1->swap(0,1);
    EXPECT_EQ(1, test1->get_data(0));
    EXPECT_EQ(6, test1->get_data(1));
}

TEST_F(Lab06Fixture, swap_tail){

    test1->swap(5,16);
    EXPECT_EQ(16, test1->get_data(5));
    EXPECT_EQ(5, test1->get_data(16));
}

TEST_F(Lab06Fixture, swap_tailnext){

    test1->swap(15,16);
    EXPECT_EQ(16, test1->get_data(15));
    EXPECT_EQ(15, test1->get_data(16));
}

TEST_F(Lab06Fixture, swap_head_and_tail){

    test1->swap(0,16);
    EXPECT_EQ(16, test1->get_data(0));
    EXPECT_EQ(0, test1->get_data(16));
}

TEST_F(Lab06Fixture, swap_head_and_tail_2_elements){
    lab6::doubly_linked_list test(0);
    test.append(1);
    EXPECT_EQ(0, test.get_data(0));
    EXPECT_EQ(1, test.get_data(1));
    test.swap(0,1);
    EXPECT_EQ(1, test.get_data(0));
    EXPECT_EQ(0, test.get_data(1));
}

TEST_F(Lab06Fixture, SwapSet){
    lab6::doubly_linked_list test2(0);
    EXPECT_EQ(0, test2.get_data(0));
    test2.append(1);
    EXPECT_EQ(1, test2.get_data(1));
    test2.append(2);
    test2.append(3);
    test2.append(4);
    test2.append(5);
    test2.append(6);
    test2.append(7);
    test2.append(8);
    test2.append(9);
    test2.swap_set(2,3,5,7);
    EXPECT_EQ(5, test2.get_data(2));
    EXPECT_EQ(6, test2.get_data(3));
    EXPECT_EQ(7, test2.get_data(4));
    EXPECT_EQ(2, test2.get_data(6));
    EXPECT_EQ(3, test2.get_data(7));
}

TEST_F(Lab06Fixture, Swap_Set_Backwards){
    test1->swap_set(7,9,3,5);
    EXPECT_EQ(7, test1->get_data(3));
    EXPECT_EQ(8, test1->get_data(4));
    EXPECT_EQ(9, test1->get_data(5));
    EXPECT_EQ(3, test1->get_data(7));
    EXPECT_EQ(4, test1->get_data(8));
    EXPECT_EQ(5, test1->get_data(9));
}

TEST_F(Lab06Fixture, SwapSet_Throw){
    EXPECT_ANY_THROW(test1->swap_set(3,6,5,8));
}

TEST_F(Lab06Fixture, SwapSet_Head){
    test1->swap_set(0,2,7,11);
    EXPECT_EQ(7, test1->get_data(0));
    EXPECT_EQ(8, test1->get_data(1));
    EXPECT_EQ(9, test1->get_data(2));
    EXPECT_EQ(10, test1->get_data(3));
    EXPECT_EQ(11, test1->get_data(4));
    EXPECT_EQ(0, test1->get_data(9));
    EXPECT_EQ(1, test1->get_data(10));
    EXPECT_EQ(2, test1->get_data(11));
}

TEST_F(Lab06Fixture, SwapSet_Head_Next){
    test1->swap_set(0,2,3,7);
    EXPECT_EQ(3, test1->get_data(0));
    EXPECT_EQ(4, test1->get_data(1));
    EXPECT_EQ(5, test1->get_data(2));
    EXPECT_EQ(6, test1->get_data(3));
    EXPECT_EQ(7, test1->get_data(4));
    EXPECT_EQ(0, test1->get_data(5));
    EXPECT_EQ(1, test1->get_data(6));
    EXPECT_EQ(2, test1->get_data(7));
}

TEST_F(Lab06Fixture, SwapSet_Tail){
    test1->swap_set(5,8,13,16);
    EXPECT_EQ(13, test1->get_data(5));
    EXPECT_EQ(14, test1->get_data(6));
    EXPECT_EQ(15, test1->get_data(7));
    EXPECT_EQ(16, test1->get_data(8));
    EXPECT_EQ(5, test1->get_data(13));
    EXPECT_EQ(6, test1->get_data(14));
    EXPECT_EQ(7, test1->get_data(15));
    EXPECT_EQ(8, test1->get_data(16));
}

TEST_F(Lab06Fixture, SwapSet_Tail_Next){
    test1->swap_set(9,12,13,16);
    EXPECT_EQ(13, test1->get_data(9));
    EXPECT_EQ(14, test1->get_data(10));
    EXPECT_EQ(15, test1->get_data(11));
    EXPECT_EQ(16, test1->get_data(12));
    EXPECT_EQ(9, test1->get_data(13));
    EXPECT_EQ(10, test1->get_data(14));
    EXPECT_EQ(11, test1->get_data(15));
    EXPECT_EQ(12, test1->get_data(16));
}

TEST_F(Lab06Fixture, SwapSet_Head_and_Tail){
    test1->swap_set(0,2,12,16);
    EXPECT_EQ(12, test1->get_data(0));
    EXPECT_EQ(13, test1->get_data(1));
    EXPECT_EQ(14, test1->get_data(2));
    EXPECT_EQ(15, test1->get_data(3));
    EXPECT_EQ(16, test1->get_data(4));
    EXPECT_EQ(0, test1->get_data(14));
    EXPECT_EQ(1, test1->get_data(15));
    EXPECT_EQ(2, test1->get_data(16));
}

TEST_F(Lab06Fixture, SwapSet_Head_and_Tail_Next){
    lab6::doubly_linked_list test(0);
    test.append(1);
    test.append(2);
    test.append(3);
    test.append(4);
    test.append(5);
    test.append(6);
    test.swap_set(0,3,4,6);
    EXPECT_EQ(4, test.get_data(0));
    EXPECT_EQ(5, test.get_data(1));
    EXPECT_EQ(6, test.get_data(2));
    EXPECT_EQ(0, test.get_data(3));
    EXPECT_EQ(1, test.get_data(4));
    EXPECT_EQ(2, test.get_data(5));
    EXPECT_EQ(3, test.get_data(6));
}

TEST_F(Lab06Fixture, Sort){
    test2->sort();
    EXPECT_EQ(0, test2->get_data(0));
    EXPECT_EQ(1, test2->get_data(1));
    EXPECT_EQ(2, test2->get_data(2));
    EXPECT_EQ(3, test2->get_data(3));
    EXPECT_EQ(4, test2->get_data(4));
    EXPECT_EQ(5, test2->get_data(5));
    EXPECT_EQ(6, test2->get_data(6));
    EXPECT_EQ(7, test2->get_data(7));
    EXPECT_EQ(8, test2->get_data(8));
}

TEST_F(Lab06Fixture, Sort_2){
    lab6::doubly_linked_list test(5);
    EXPECT_EQ(5, test.get_data(0));
    test.sort();
    EXPECT_EQ(5, test.get_data(0));
}

TEST_F(Lab06Fixture, Sort_3){
    lab6::doubly_linked_list test;
    EXPECT_ANY_THROW(test.sort());
}