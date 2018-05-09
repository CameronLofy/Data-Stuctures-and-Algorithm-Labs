#include "gtest/gtest.h"
#include "../lib/lab08/inc/hash_table.h"
#include "../lib/lab08/src/sorts.cpp"
#include "../lib/lab06/inc/doubly_linked_list.h"

class Lab08SortsFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        test_numbers=std::vector<unsigned>({12,8,14,15,18,16,17,19,22,20,4,10,9,13,11,5,7,6,2,1,3});

    }

public:
    lab6::doubly_linked_list *to_sort_short, *to_sort_long;
    std::vector <unsigned> test_numbers;

};


class Lab08SortsProfiler : public ::testing::Test {
protected:
    virtual void SetUp(){

    }
public:
    lab6::doubly_linked_list *list_16, *list_32, *list_64, *list_128, *list_256, *list_512, *list_1024, *list_2048, *list_4096, *list_8192, *list_16384, *list_32768;
};

TEST_F(Lab08SortsFixture, mergeSort){
    std::vector<int> leftVec;
    std::vector<int> rightVec;
    std::vector<int> merged;

    leftVec=std::vector<int>({1,3,5,7});
    rightVec=std::vector<int>({2,4,6,8});

    merged=std::vector<int>({1,2,3,4,5,6,7,8});

    lab6::doubly_linked_list left(leftVec);
    lab6::doubly_linked_list right(rightVec);
    lab6::doubly_linked_list final;
    EXPECT_EQ(4, left.size());
    EXPECT_EQ(4, right.size());
    final = lab6::merge(left, right);



}