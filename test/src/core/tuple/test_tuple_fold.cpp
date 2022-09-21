// Copyright 2017, 2019, 2021, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/tuple/fold.h"

using namespace core;

TEST(TupleFold, FoldL)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::fold_l([](auto x, auto y) { return x - y; }, 7.0, tup);
    EXPECT_EQ(r, 1.0);
}

TEST(TupleFold, FoldR)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::fold_r([](auto x, auto y) { return x - y; }, 7.0, tup);
    EXPECT_EQ(r, 1.0);
}

TEST(TupleFold, AnyFalse)
{
    auto tup1 = std::make_tuple(false, false, false);
    auto r = tp::any(tup1);
    EXPECT_EQ(r, false);
}

TEST(TupleFold, AnyTrue)
{
    auto tup1 = std::make_tuple(false, true, false);
    auto r = tp::any(tup1);
    EXPECT_EQ(r, true);
}

TEST(TupleFold, AllFalse)
{
    auto tup1 = std::make_tuple(false, true, true);
    auto r = tp::all(tup1);
    EXPECT_EQ(r, false);
}

TEST(TupleFold, AllTrue)
{
    auto tup1 = std::make_tuple(true, true, true);
    auto r = tp::all(tup1);
    EXPECT_EQ(r, true);
}

TEST(TupleFold, NoneTrue)
{
    auto tup1 = std::make_tuple(false, false, false);
    auto r = tp::none(tup1);
    EXPECT_EQ(r, true);
}

TEST(TupleFold, NoneFalse)
{
    auto tup1 = std::make_tuple(false, true, false);
    auto r = tp::none(tup1);
    EXPECT_EQ(r, false);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



