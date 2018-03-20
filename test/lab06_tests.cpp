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

        test3 = new lab6::doubly_linked_list(10);
        test3->append(9);
        test3->append(8);
        test3->append(7);
        test3->append(6);
        test3->append(5);
        test3->append(4);
        test3->append(3);
        test3->append(2);
        test3->append(1);
        test3->append(0);

        test4 = new lab6::doubly_linked_list(5);
        test4->append(3);
        test4->append(11);
        test4->append(7);
        test4->append(1);
        test4->append(4);
        test4->append(3);
        test4->append(11);
        test4->append(8);
        test4->append(5);
        test4->append(2);
        test4->append(3);
        test4->append(6);



    }

    virtual void TearDown() {
        delete test1;
        delete test2;
        delete test3;
        delete test4;
    }

public:
    lab6::doubly_linked_list *test1;
    lab6::doubly_linked_list *test2;
    lab6::doubly_linked_list *test3;
    lab6::doubly_linked_list *test4;
};

TEST_F(Lab06Fixture, Constructor){
    EXPECT_EQ(0, test1->get_data(0));
    EXPECT_EQ(1, test1->get_data(1));
    EXPECT_EQ(17, test1->size());
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

TEST_F(Lab06Fixture, Sort_4){
    test3->sort();
    EXPECT_EQ(0, test3->get_data(0));
    EXPECT_EQ(1, test3->get_data(1));
    EXPECT_EQ(2, test3->get_data(2));
    EXPECT_EQ(3, test3->get_data(3));
    EXPECT_EQ(4, test3->get_data(4));
    EXPECT_EQ(5, test3->get_data(5));
    EXPECT_EQ(6, test3->get_data(6));
    EXPECT_EQ(7, test3->get_data(7));
    EXPECT_EQ(8, test3->get_data(8));
    EXPECT_EQ(9, test3->get_data(9));
    EXPECT_EQ(10, test3->get_data(10));
}

TEST_F(Lab06Fixture, Sort_5){
    test4->sort();
    EXPECT_EQ(1, test4->get_data(0));
    EXPECT_EQ(2, test4->get_data(1));
    EXPECT_EQ(3, test4->get_data(2));
    EXPECT_EQ(3, test4->get_data(3));
    EXPECT_EQ(3, test4->get_data(4));
    EXPECT_EQ(4, test4->get_data(5));
    EXPECT_EQ(5, test4->get_data(6));
    EXPECT_EQ(5, test4->get_data(7));
    EXPECT_EQ(6, test4->get_data(8));
    EXPECT_EQ(7, test4->get_data(9));
    EXPECT_EQ(8, test4->get_data(10));
    EXPECT_EQ(11, test4->get_data(11));
    EXPECT_EQ(11, test4->get_data(12));

}

TEST_F(Lab06Fixture, Operator_Plus){
    lab6::doubly_linked_list plus;
    lab6::doubly_linked_list Test_1(lab6::doubly_linked_list &test1);
    lab6::doubly_linked_list Test_2(lab6::doubly_linked_list &test2);

}

TEST(doubly_linked_list,addTest) {
    lab6::doubly_linked_list testLL1(32);
    testLL1.append(14);
    testLL1.append(6);
    testLL1.append(73);

    lab6::doubly_linked_list testLL2(9);
    testLL2.append(57);
    testLL2.append(12);
    testLL2.append(88);
    testLL2.append(29);

    lab6::doubly_linked_list temp;


    //basic add
    temp = testLL1 + testLL2;
    EXPECT_EQ(32, temp.get_data(0));
    EXPECT_EQ(14, temp.get_data(1));
    EXPECT_EQ(6, temp.get_data(2));
    EXPECT_EQ(73, temp.get_data(3));
    EXPECT_EQ(9, temp.get_data(4));
    EXPECT_EQ(57, temp.get_data(5));
    EXPECT_EQ(12, temp.get_data(6));
    EXPECT_EQ(88, temp.get_data(7));
    EXPECT_EQ(29, temp.get_data(8));

}

TEST(doubly_linked_list, copyConstructorTest)
{
    lab6::doubly_linked_list testLL(1);
    testLL.append(2);
    lab6::doubly_linked_list newLL(testLL);

    newLL.append(5);
    EXPECT_EQ(5, newLL.get_data(2));              //Add something new to new LL
    EXPECT_EQ(3, newLL.size());
    EXPECT_EQ(2, testLL.get_data(1));
    EXPECT_EQ(2, testLL.size());
}






