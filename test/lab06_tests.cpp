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


    }

    virtual void TearDown() {
    }

public:
    lab6::doubly_linked_list *test1;
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

TEST_F(Lab06Fixture, append){
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