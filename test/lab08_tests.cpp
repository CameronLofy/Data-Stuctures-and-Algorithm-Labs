#include "gtest/gtest.h"
#include "../lib/lab08/inc/hash_table.h"
#include "../lib/lab08/src/sorts.cpp"
#include "../lib/lab06/inc/doubly_linked_list.h"

class Lab08SortsFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        test_numbers=std::vector<int>({12,8,14,15,18,16,17,19,22,20,4,10,9,13,11,5,7,6,2,1,3});
        lab6::doubly_linked_list test1(test_numbers);

    }

public:
    lab6::doubly_linked_list *to_sort_short, *to_sort_long;
    lab6::doubly_linked_list *test1;
    std::vector <int> test_numbers;

};


class Lab08SortsProfiler : public ::testing::Test {
protected:
    virtual void SetUp(){

    }
public:
    lab6::doubly_linked_list *list_16, *list_32, *list_64, *list_128, *list_256, *list_512, *list_1024, *list_2048, *list_4096, *list_8192, *list_16384, *list_32768;
};

TEST_F(Lab08SortsFixture, merge){
    std::vector<int> leftSmall;
    std::vector<int> rightSmall;
    std::vector<int> leftVec;
    std::vector<int> rightVec;
    std::vector<int> merged;
    std::vector<int> leftVec2;
    std::vector<int> rightVec2;
    std::vector<int> merged2;

    leftSmall = std::vector<int>({5});
    rightSmall = std::vector<int>({3});

    lab6::doubly_linked_list leftS(leftSmall);
    lab6::doubly_linked_list rightS(rightSmall);
    lab6::doubly_linked_list finalS;

    finalS = lab6::merge(leftS, rightS);

    leftVec=std::vector<int>({1,3,5,7});
    rightVec=std::vector<int>({2,4,6,8});

    merged=std::vector<int>({1,2,3,4,5,6,7,8});

    lab6::doubly_linked_list left(leftVec);
    lab6::doubly_linked_list right(rightVec);
    lab6::doubly_linked_list final;
    EXPECT_EQ(4, left.size());
    EXPECT_EQ(4, right.size());
    final = lab6::merge(left, right);

    leftVec2=std::vector<int>({1,1,2,2,3,3,8,8,9,9});
    rightVec2=std::vector<int>({4,4,5,5,6,6,7,7,8,9,10,10,11,11});

    merged2=std::vector<int>({1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,8,9,9,9,10,10,11,11});

    lab6::doubly_linked_list left2(leftVec2);
    lab6::doubly_linked_list right2(rightVec2);
    lab6::doubly_linked_list final2;
    EXPECT_EQ(4, left.size());
    EXPECT_EQ(4, right.size());
    final2 = lab6::merge(left2, right2);


}

TEST_F(Lab08SortsFixture, mergeBig){
    std::vector <int>test1;
    std::vector <int>test2;
    std::vector <int>final;
    for(int i=1; i<200; i++) {
        test1.push_back(i);
        i++;
    }
    for(int i=2; i<200; i++) {
        test2.push_back(i);
        i++;
    }
    for(int i=1; i<200; i++){
        final.push_back(i);
    }
    lab6::doubly_linked_list left(test1);
    lab6::doubly_linked_list right(test2);
    lab6::doubly_linked_list merged;
    merged = lab6::merge(left, right);
    for(int i=0; i<199; i++) {
        EXPECT_EQ(final.at(i), merged.get_data(i));
    }
}

TEST_F(Lab08SortsFixture, MergeSort){
    std::vector<int> sorted;
    std::vector<int> sorted_simple;
    std::vector<int> to_sort_simple;
    sorted = std::vector<int>({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22});
    sorted_simple = std::vector<int>({1,2,3,4,5});
    to_sort_simple = std::vector<int>({5,3,4,1,2});


    lab6::doubly_linked_list to_sort(test_numbers);
    lab6::mergesort(to_sort);
    for(int i=0; i<21; i++) {
        EXPECT_EQ(sorted.at(i), to_sort.get_data(i));
    }

    lab6::doubly_linked_list simple(to_sort_simple);
    lab6::mergesort(simple);
    for(int i=0; i<5; i++) {
        EXPECT_EQ(sorted_simple.at(i), simple.get_data(i));
    }
}

TEST_F(Lab08SortsFixture, Quicksort){
    int to_sort[] = {5,2,8,6,3,1,7};
    int sorted[] = {1,2,3,5,6,7,8};

    lab6::quicksort(to_sort,0,6);
    for(int i=0; i<7; i++){
        EXPECT_EQ(sorted[i], to_sort[i]);
    }
}