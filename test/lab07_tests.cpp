#include "gtest/gtest.h"
#include "../lib/lab07/inc/tree.h"

class Lab07Fixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        test_numbers=std::vector<unsigned>({12,8,14,15,18,16,17,19,22,20,4,10,9,13,11,5,7,6,2,1,3});
        tree = new lab7::tree();

        built_tree = new lab7::tree();
        for(auto it = test_numbers.begin(); it<test_numbers.end(); ++it) built_tree->insert(*it);
    }

public:
    lab7::tree *tree, *built_tree;
    std::vector <unsigned> test_numbers;

};
TEST_F(Lab07Fixture, construct_with_check_size) {
    EXPECT_EQ(tree->size(), 0);
    EXPECT_EQ(tree->depth(), 0);
}

TEST_F(Lab07Fixture, depth)
{
    EXPECT_EQ(built_tree->depth(), 6);
    built_tree->insert(4);
    EXPECT_EQ(built_tree->depth(), 6);
    built_tree->insert(20);
    EXPECT_EQ(built_tree->depth(), 6);
    built_tree->insert(21);
    EXPECT_EQ(built_tree->depth(), 7);
}

TEST_F(Lab07Fixture, size)
{
    EXPECT_EQ(built_tree->size(), 21);
    built_tree->insert(4);
    EXPECT_EQ(built_tree->size(), 22);
    built_tree->insert(20);
    EXPECT_EQ(built_tree->size(), 23);
    built_tree->insert(21);
    EXPECT_EQ(built_tree->size(), 24);
}

TEST_F(Lab07Fixture, frequency)
{
    EXPECT_EQ(built_tree->get_frequency(21), 0);
    EXPECT_EQ(built_tree->get_frequency(12), 1);
    EXPECT_EQ(built_tree->get_frequency(4), 1);
    built_tree->insert(4);
    EXPECT_EQ(built_tree->get_frequency(4), 2);
    built_tree->insert(4);
    EXPECT_EQ(built_tree->get_frequency(4), 3);
    built_tree->insert(4);
    EXPECT_EQ(built_tree->get_frequency(4), 4);
    built_tree->insert(21);
    EXPECT_EQ(built_tree->get_frequency(21), 1);
}

TEST_F(Lab07Fixture, level)
{
    EXPECT_EQ(built_tree->level(12), 0);
    EXPECT_EQ(built_tree->level(20), 6);
    EXPECT_EQ(built_tree->level(3), 4);
    EXPECT_EQ(built_tree->level(11), 3);
    EXPECT_EQ(built_tree->level(0), -1);
    EXPECT_EQ(built_tree->level(21), -1);
}

TEST_F(Lab07Fixture, in_tree)
{
    EXPECT_EQ(built_tree->in_tree(0), false);
    EXPECT_EQ(built_tree->in_tree(4), true);
    EXPECT_EQ(built_tree->in_tree(15), true);
    EXPECT_EQ(built_tree->in_tree(21), false);
}

TEST_F(Lab07Fixture, path_to)
{
    testing::internal::CaptureStdout();
    built_tree->path_to(8);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("12 -> 8\n"));

    testing::internal::CaptureStdout();
    built_tree->path_to(6);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("12 -> 8 -> 4 -> 5 -> 7 -> 6\n"));

    testing::internal::CaptureStdout();
    built_tree->path_to(18);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("12 -> 14 -> 15 -> 18\n"));

    testing::internal::CaptureStdout();
    built_tree->path_to(13);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("12 -> 14 -> 13\n"));

    testing::internal::CaptureStdout();
    built_tree->path_to(0);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string(""));

    built_tree->insert(8);
    testing::internal::CaptureStdout();
    built_tree->path_to(4);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("12 -> 8 -> 4\n"));

    built_tree->insert(16);
    testing::internal::CaptureStdout();
    built_tree->path_to(16);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("12 -> 14 -> 15 -> 18 -> 16\n"));
}

TEST_F(Lab07Fixture, print)
{
    testing::internal::CaptureStdout();
    built_tree->print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 22 \n"));

    built_tree->insert(4);
    built_tree->insert(4);
    built_tree->insert(4);
    built_tree->insert(11);
    built_tree->insert(16);

    testing::internal::CaptureStdout();
    built_tree->print();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("1 2 3 4 4 4 4 5 6 7 8 9 10 11 11 12 13 14 15 16 16 17 18 19 20 22 \n"));
}

TEST_F(Lab07Fixture, remove_mult)
{
    built_tree->insert(6);
    EXPECT_EQ(built_tree->get_frequency(6), 2);
    EXPECT_EQ(built_tree->remove(6), true);
    EXPECT_EQ(built_tree->get_frequency(6), 1);
    EXPECT_EQ(built_tree->size(), 21);
}

TEST_F(Lab07Fixture, remove_single)
{
    EXPECT_EQ(built_tree->get_frequency(6), 1);
    EXPECT_EQ(built_tree->remove(6), true);
    EXPECT_EQ(built_tree->get_frequency(6), 0);
    EXPECT_EQ(built_tree->size(), 20);
}

TEST_F(Lab07Fixture, remove_nonexistant)
{
    EXPECT_EQ(built_tree->get_frequency(21), 0);
    EXPECT_EQ(built_tree->remove(21), false);
    EXPECT_EQ(built_tree->get_frequency(21), 0);
    EXPECT_EQ(built_tree->size(), 21);
}

TEST_F(Lab07Fixture, remove_parent)
{
    EXPECT_EQ(built_tree->get_frequency(4), 1);
    EXPECT_EQ(built_tree->remove(4), true);
    EXPECT_EQ(built_tree->get_frequency(4), 0);
    EXPECT_EQ(built_tree->size(), 20);
}

TEST_F(Lab07Fixture, remove_root)
{
    EXPECT_EQ(built_tree->get_frequency(12), 1);
    EXPECT_EQ(built_tree->remove(12), true);
    EXPECT_EQ(built_tree->get_frequency(12), 0);
    EXPECT_EQ(built_tree->size(), 20);
}

TEST_F(Lab07Fixture, insert){
    tree->insert(10);
    EXPECT_EQ(tree->size(), 1);
    EXPECT_EQ(tree->depth(), 0);
    tree->insert(7);
    EXPECT_EQ(tree->size(), 2);
    EXPECT_EQ(tree->depth(), 1);
}

TEST_F(Lab07Fixture, values_above){
    std::vector<int> compare = std::vector<int>({13,14,15,16,17,18,19,20,22});
    EXPECT_EQ(built_tree->values_above(12), compare);

    built_tree->values_above(13);
    built_tree->insert(10);
    built_tree->insert(13);
    built_tree->insert(13);
    built_tree->insert(15);
    built_tree->insert(19);

    compare = std::vector<int>({17,18,19,19,20,22});
    EXPECT_EQ(built_tree->values_above(16), compare);

    compare = std::vector<int>({11,12,13,13,13,14,15,15,16,17,18,19,19,20,22});
    EXPECT_EQ(built_tree->values_above(10), compare);

    compare = std::vector<int>({22});
    EXPECT_EQ(built_tree->values_above(20), compare);

    compare = std::vector<int>({7,8,9,10,10,11,12,13,13,13,14,15,15,16,17,18,19,19,20,22});
    EXPECT_EQ(built_tree->values_above(6), compare);
}

TEST_F(Lab07Fixture, equals_operator){
    EXPECT_NO_FATAL_FAILURE(*tree = *built_tree);
    EXPECT_TRUE(built_tree->in_tree(15));
    EXPECT_TRUE(tree->in_tree(15));

    built_tree->remove(15);

    EXPECT_FALSE(built_tree->in_tree(15));
    EXPECT_TRUE(tree->in_tree(15));

    EXPECT_FALSE(built_tree->in_tree(21));
    EXPECT_FALSE(tree->in_tree(21));

    tree->insert(21);

    EXPECT_FALSE(built_tree->in_tree(21));
    EXPECT_TRUE(tree->in_tree(21));
}