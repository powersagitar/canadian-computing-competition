#include "gtest/gtest.h"

#include "../2019/J3.cc"

namespace
{
    TEST(J3, targetIsChar)
    {
        EXPECT_EQ(debug::continuousCount("5", 0, "5"), 1);
        EXPECT_EQ(debug::continuousCount("55555678", 0, '5'), 5);

        // these two cases are not considered
        // EXPECT_EQ(debug::continuousCount("55555678", 0, 6), 1);
        // EXPECT_EQ(debug::continuousCount("55555678", 0, 1), 0);
    }

    TEST(J3, targetIsString)
    {
        EXPECT_EQ(debug::continuousCount("hellohelloworld", 0, "hello"), 2);
    }
} // namespace