#include "gtest/gtest.h"
#include "doubly_linked_list.h"

class Lab06Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {


    }

    virtual void TearDown() {
    }

public:
};

TEST_F(Lab06Fixture, Constructor){
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