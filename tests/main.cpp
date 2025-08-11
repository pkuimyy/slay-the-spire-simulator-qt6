#include <gtest/gtest.h>

TEST(CoreSystemTest, AddsCorrectly) {
    EXPECT_EQ(2 + 3, 5);
}

TEST(CoreSystemTest, HandlesZero) {
    EXPECT_EQ(0 + 0, 0);
}
