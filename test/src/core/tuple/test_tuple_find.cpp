// Copyright 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/tuple/find.h"

using namespace core;

TEST(TupleFind, FindFirstSuccess)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::find_first(tup, [](auto& x) { return x == 2.0; });
    EXPECT_EQ(r, 1);
}

TEST(TupleFind, FindFirstFailure)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::find_first(tup, [](auto& x) { return x == 4.0; });
    EXPECT_EQ(r, -1);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



