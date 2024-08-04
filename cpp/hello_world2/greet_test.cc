#include <gtest/gtest.h>
#include "greet.h"

TEST(GreetTest, GreetsWorld) {
    EXPECT_EQ(greet("World"), "Hello, World!");
}