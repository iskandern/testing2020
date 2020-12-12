//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>



TEST(IsLeap, isLeapTest1) {
    ASSERT_THROW(IsLeap(0), std::invalid_argument);
}

TEST(IsLeap, isLeapTest2) {
    ASSERT_TRUE(IsLeap(4));
    ASSERT_FALSE(IsLeap(5));
}

TEST(IsLeap, isLeapTest3) {
    ASSERT_FALSE(IsLeap(100));
    ASSERT_FALSE(IsLeap(101));
}

TEST(IsLeap, isLeapTest4) {
    ASSERT_FALSE(IsLeap(300));
    ASSERT_TRUE(IsLeap(400));
}


