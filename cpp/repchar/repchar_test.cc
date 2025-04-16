#include "repchar.h"
#include <gtest/gtest.h>

TEST(RepChar, ZeroLength) {
    RepChar* result = generate('a', 0);
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(0, result->length);
    ASSERT_NE(nullptr, result->data);
    ASSERT_STREQ("", result->data);
    delete[] result->data;
    delete result;
}

TEST(RepChar, CorrectResult) {
    RepChar* result = generate('b', 5);
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(5, result->length);
    ASSERT_NE(nullptr, result->data);
    ASSERT_STREQ("bbbbb", result->data);
    delete[] result->data;
    delete result;
}

TEST(RepChar, NegativeLength) {
    RepChar* result = generate('c', -3);
    ASSERT_EQ(nullptr, result);
}
