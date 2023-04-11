#include "math.h"
#include <gtest/gtest.h>

TEST(Add, CorrectResult) {
    ASSERT_EQ(Add(0, 0), 0);
    ASSERT_EQ(Add(0, 1), 1);
    ASSERT_EQ(Add(1, 2), 3);
}
