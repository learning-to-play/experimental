#include "math.h"
#include <gtest/gtest.h>

TEST(Add, CorrectResult) {
    ASSERT_EQ(Add(0, 0), 0);
    ASSERT_EQ(Add(1, 2), 3);
    ASSERT_EQ(Add(-1, -2), -3) << "Incorrect result for adding negative integers";
}
