#include "gtest/gtest.h"
#include "stringVector.h"
#include "expressionstream.h"


class Lab02Fixture : public ::testing::Test {
protected:
    virtual void TearDown() {
        delete container1;
    }
    virtual void SetUp() {
    }
public:
    lab2::stringVector * container1;
};


TEST(crashTest , crashTest_vectorconstructorTest_Test) {
    lab2::stringVector * test_container =new lab2::stringVector(); // just a test to ensure the constructor works without crashing
    delete test_container;//test destructor
}


TEST_F(Lab02Fixture, basic_append_and_destructor_test) {
    container1 = new lab2::stringVector();
    container1->append(std::string("123"));
    container1->append(std::string("+"));
    container1->append(std::string("456"));
}


TEST_F(Lab02Fixture, basic_reserve_capacity_test) {
    container1 = new lab2::stringVector();
    EXPECT_EQ(0,container1 -> capacity());
    EXPECT_TRUE(container1->empty());

    container1->reserve(4);
    EXPECT_EQ(4,container1->capacity());
    EXPECT_EQ(0,container1->size());
    EXPECT_TRUE(container1->empty());

    container1->reserve(10000);
    EXPECT_EQ(10000, container1->capacity());

    container1->reserve(6);
    EXPECT_EQ(6, container1->capacity());

    container1->reserve(0);
    EXPECT_TRUE(container1->empty());
}

TEST_F(Lab02Fixture, stringVector_append_crash_test){
    container1 = new lab2::stringVector();

    EXPECT_TRUE(container1->empty());
    EXPECT_EQ(0,container1->size());

    container1->append("some string");
    EXPECT_FALSE(container1->empty());
    EXPECT_EQ(1,container1->size());

    container1->append("some other string");
    EXPECT_FALSE(container1->empty());
    EXPECT_EQ(2,container1->size());

    container1->append("some other other string");
    EXPECT_FALSE(container1->empty());
    EXPECT_EQ(3,container1->size());

    container1->append("some other other other string");
    EXPECT_FALSE(container1->empty());
    EXPECT_EQ(4,container1->size());
}


TEST_F(Lab02Fixture, stringVector_append_access_test) {
    container1 = new lab2::stringVector();

    EXPECT_ANY_THROW(container1->operator[](0));
    EXPECT_ANY_THROW(container1->operator[](10));
    EXPECT_ANY_THROW(container1->operator[](-6));

    EXPECT_TRUE(container1->empty());
    EXPECT_EQ(0,container1->size());

    container1->append("some string");
    EXPECT_EQ("some string",container1->operator[](0));

    container1->append("some other string");
    EXPECT_EQ("some string",container1->operator[](0));
    EXPECT_EQ("some other string",container1->operator[](1));

    container1->append("some other other string");
    EXPECT_EQ("some string",container1->operator[](0));
    EXPECT_EQ("some other string",container1->operator[](1));
    EXPECT_EQ("some other other string",container1->operator[](2));

    container1->append("some other other other string");
    EXPECT_EQ("some string",container1->operator[](0));
    EXPECT_EQ("some other string",container1->operator[](1));
    EXPECT_EQ("some other other string",container1->operator[](2));
    EXPECT_EQ("some other other other string",container1->operator[](3));

    for(int i =0; i<container1->size(); i++){container1->operator[](i)=container1->operator[](container1->size()-1-i);}

    container1->append("some other other other string");
    EXPECT_EQ("some other other other string",container1->operator[](0));
    EXPECT_EQ("some other other string",container1->operator[](1));
    EXPECT_EQ("some other other string",container1->operator[](2));
    EXPECT_EQ("some other other other string",container1->operator[](3));

    container1->reserve(1);
    EXPECT_ANY_THROW(container1->operator[](3));
    EXPECT_EQ("some other other other string",container1->operator[](0));
}


TEST_F(Lab02Fixture, stringVector_opEq_access_test) {
    container1 = new lab2::stringVector();
    lab2::stringVector* container2 = new lab2::stringVector();

    container1->append("some string");
    container1->append("some other string");
    container1->append("some other other string");
    container1->append("some other other other string");

    EXPECT_EQ("some string",container1->operator[](0));
    EXPECT_EQ("some other string",container1->operator[](1));
    EXPECT_EQ("some other other string",container1->operator[](2));
    EXPECT_EQ("some other other other string",container1->operator[](3));

    container1->operator=(*container1);

    EXPECT_EQ("some string",container1->operator[](0));
    EXPECT_EQ("some other string",container1->operator[](1));
    EXPECT_EQ("some other other string",container1->operator[](2));
    EXPECT_EQ("some other other other string",container1->operator[](3));

    container2->operator=(*container1);

    EXPECT_EQ("some string",container2->operator[](0));
    EXPECT_EQ("some other string",container2->operator[](1));
    EXPECT_EQ("some other other string",container2->operator[](2));
    EXPECT_EQ("some other other other string",container2->operator[](3));

    container2 ->operator[](0) = "a different string";
    container2 ->operator[](1) = "a different different string";
    container2 ->operator[](2) = "a different different different string";
    container2 ->operator[](3) = "a different different different different string";

    EXPECT_EQ("a different string",container2->operator[](0));
    EXPECT_EQ("a different different string",container2->operator[](1));
    EXPECT_EQ("a different different different string",container2->operator[](2));
    EXPECT_EQ("a different different different different string",container2->operator[](3));

    EXPECT_EQ("some string",container1->operator[](0));
    EXPECT_EQ("some other string",container1->operator[](1));
    EXPECT_EQ("some other other string",container1->operator[](2));
    EXPECT_EQ("some other other other string",container1->operator[](3));
}


TEST_F(Lab02Fixture, stringVector_swap_access_test) {
    container1 = new lab2::stringVector();

    container1->append("some string");
    container1->append("some other string");
    container1->append("some other other string");
    container1->append("some other other other string");

    container1->swap(0,3);
    container1->swap(1,2);

    EXPECT_EQ("some string",container1->operator[](3));
    EXPECT_EQ("some other string",container1->operator[](2));
    EXPECT_EQ("some other other string",container1->operator[](1));
    EXPECT_EQ("some other other other string",container1->operator[](0));
}


TEST_F(Lab02Fixture, stringVector_sort_access_test) {
    container1 = new lab2::stringVector;

    container1->append("yellow");
    container1->append("glad");
    container1->append("california");
    container1->append("question");
    container1->append("bear");
    container1->append("restful");
    container1->append("extra");
    container1->append("nugget");
    container1->append("door");
    container1->append("vehicle");
    container1->append("full");
    container1->append("know");
    container1->append("later");
    container1->append("apple");
    container1->append("true");
    container1->append("joker");
    container1->append("xeon");
    container1->append("welcome");
    container1->append("mannequin");
    container1->append("oriented");
    container1->append("programming");
    container1->append("hello");
    container1->append("sleep");
    container1->append("igloo");
    container1->append("object");
    container1->append("under");
    container1->append("fail");

    container1->sort();

    EXPECT_EQ("apple",container1->operator[](0));
    EXPECT_EQ("bear",container1->operator[](1));
    EXPECT_EQ("california",container1->operator[](2));
    EXPECT_EQ("door",container1->operator[](3));
    EXPECT_EQ("extra",container1->operator[](4));
    EXPECT_EQ("fail",container1->operator[](5));
    EXPECT_EQ("full",container1->operator[](6));
    EXPECT_EQ("glad",container1->operator[](7));
    EXPECT_EQ("hello",container1->operator[](8));
    EXPECT_EQ("igloo",container1->operator[](9));
    EXPECT_EQ("joker",container1->operator[](10));
    EXPECT_EQ("know",container1->operator[](11));
    EXPECT_EQ("later",container1->operator[](12));
    EXPECT_EQ("mannequin",container1->operator[](13));
    EXPECT_EQ("nugget",container1->operator[](14));
    EXPECT_EQ("object",container1->operator[](15));
    EXPECT_EQ("oriented",container1->operator[](16));
    EXPECT_EQ("programming",container1->operator[](17));
    EXPECT_EQ("question",container1->operator[](18));
    EXPECT_EQ("restful",container1->operator[](19));
    EXPECT_EQ("sleep",container1->operator[](20));
    EXPECT_EQ("true",container1->operator[](21));
    EXPECT_EQ("under",container1->operator[](22));
    EXPECT_EQ("vehicle",container1->operator[](23));
    EXPECT_EQ("welcome",container1->operator[](24));
    EXPECT_EQ("xeon",container1->operator[](25));
    EXPECT_EQ("yellow",container1->operator[](26));
}