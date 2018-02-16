#include "gtest/gtest.h"
#include "fifo.h"
#include "lifo.h"
#include "stringVector.h"

class Lab03Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        TestVec = new lab3::fifo;


    }

    virtual void TearDown() {
    }

public:
    lab3::fifo * TestVec;
};

TEST()