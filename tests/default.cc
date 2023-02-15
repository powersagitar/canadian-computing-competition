#include "gtest/gtest.h"

#include "../2019/J3.cc"

TEST(Bundle1, Test1)
{
    EXPECT_EQ(debug::continuousCount("555556", 0, 5), 5);
}