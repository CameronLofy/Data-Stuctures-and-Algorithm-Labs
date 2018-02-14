#include "gtest/gtest.h"
#include "stringVector.h"

class Lab02Fixture : public ::testing::Test {

};


TEST(stringVector,constructorTest) {
    lab2::stringVector hw0;
    EXPECT_TRUE(hw0.empty());
    EXPECT_EQ(0,hw0.size());
    EXPECT_EQ(0,hw0.capacity());
}

TEST(stringVector,overloadBracket){
    lab2::stringVector hw1;
    hw1.append("Hello");
    EXPECT_EQ("Hello",hw1[0]);
    hw1.append("Entry Number 2");
    EXPECT_EQ("Entry Number 2",hw1[1]);
    hw1[0] = "Entry 1";
    EXPECT_EQ("Entry 1",hw1[0]);
}

TEST(stringVector,variableAllocation){
    lab2::stringVector hw2;
    hw2.append("Test 1");
    hw2.append("Test 2");
    EXPECT_EQ(2,hw2.size());
    EXPECT_EQ(2,hw2.capacity());
    hw2.append("Test 3");
    EXPECT_EQ(3,hw2.size());
    EXPECT_EQ(4,hw2.capacity());
    EXPECT_EQ("Test 1",hw2[0]);
    EXPECT_EQ("Test 2",hw2[1]);
}

TEST(stringVector,pointerTest) {
    lab2::stringVector* hw3 = new lab2::stringVector;
    EXPECT_TRUE(hw3->empty());
    delete hw3;
}

TEST(stringVector,reserveTruncation){
    lab2::stringVector* hw4 = new lab2::stringVector;

    hw4->append("line 1");
    hw4->append("line 2");
    hw4->append("line 3");
    hw4->append("line 4");
    hw4->append("line 5");
    hw4->append("line 6");

    hw4->reserve(8);
    EXPECT_EQ(8, hw4->capacity());
    EXPECT_EQ(6, hw4->size());

    hw4->reserve(4);
    EXPECT_EQ(4, hw4->size());
    EXPECT_EQ(4, hw4->capacity());

    hw4->reserve(2);
    EXPECT_EQ(2, hw4->size());
    EXPECT_EQ(2, hw4->capacity());

    hw4->append("line 3");
    EXPECT_EQ(3, hw4->size());
    EXPECT_EQ(4, hw4->capacity());



    delete hw4;
}

TEST(stringVector, reserve){
    lab2::stringVector hw9;
    EXPECT_EQ(0, hw9.size());
    EXPECT_EQ(0, hw9.capacity());
    hw9.reserve(3);
    EXPECT_EQ(0, hw9.size());
    EXPECT_EQ(3, hw9.capacity());
    hw9.append("Test String");
    EXPECT_EQ("Test String",hw9[0]);
}

TEST(stringVector, append){
    lab2::stringVector hw10;
    hw10.append("hello");
    hw10.append("sir");
    EXPECT_EQ("hello", hw10[0]);
    EXPECT_EQ("sir", hw10[1]);
}

TEST(stringVector,expectionTesting){
    lab2::stringVector hw5;
    hw5.reserve(2);
    hw5.append("Test String");
    EXPECT_EQ("Test String",hw5[0]);
    EXPECT_EQ("",hw5[1]);
    EXPECT_THROW(hw5[3],std::string);

    EXPECT_NO_THROW(hw5.swap(0,1));
    EXPECT_EQ("",hw5[0]);
    EXPECT_EQ("Test String",hw5[1]);
    EXPECT_THROW(hw5.swap(0,2),std::string);
}

TEST(stringVector, throwExecption) {
    lab2::stringVector hw5;
    hw5.reserve(2);
    hw5.append("Test String");
    EXPECT_EQ("Test String", hw5[0]);
    EXPECT_EQ("", hw5[1]);
    EXPECT_THROW(hw5[2], std::string);
}

TEST(stringVector,overloadAssignment){
    lab2::stringVector hw6;
    for (int i=0;i<6;i++){
        hw6.append(std::to_string(i));
    }
    EXPECT_EQ(6,hw6.size());
    EXPECT_EQ(8,hw6.capacity());
    EXPECT_EQ("5",hw6[5]);

    lab2::stringVector* hw7 = new lab2::stringVector;
    *hw7 = hw6;
    EXPECT_EQ(6,hw7->size());
    EXPECT_EQ(8,hw7->capacity());
    EXPECT_EQ("5",(*hw7)[5]);
}

TEST(stringVector,sorting) {
    lab2::stringVector hw8;
    hw8.append("Part 3");
    hw8.append("Part 1");
    hw8.append("Part 4");
    hw8.append("Part 2");
    hw8.append("Part Test");
    hw8.append("Test 1");
    hw8.append("Temporary Test");

    EXPECT_NO_THROW(hw8.sort());
    EXPECT_EQ("Part 1",hw8[0]);
    EXPECT_EQ("Part 2",hw8[1]);
    EXPECT_EQ("Part 3",hw8[2]);
    EXPECT_EQ("Part 4",hw8[3]);
    EXPECT_EQ("Part Test",hw8[4]);
    EXPECT_EQ("Temporary Test",hw8[5]);
    EXPECT_EQ("Test 1",hw8[6]);
}