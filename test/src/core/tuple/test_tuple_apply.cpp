// Copyright 2017, 2019, 2021, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/tuple/apply.h"

using namespace core;

TEST(TupleApply, Apply)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    tp::apply([](auto& x) { x += 1.0; }, tup);
    EXPECT_EQ(std::get<0>(tup), 2.0);
    EXPECT_EQ(std::get<1>(tup), 3.0);
    EXPECT_EQ(std::get<2>(tup), 4.0);
}

TEST(TupleApply, ApplyN)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto tup2 = std::make_tuple(4.0, 5.0, 6.0);
    tp::apply_n([](auto& x, auto& y) { x += 1.0; y += 2.0; }, tup, tup2);
    EXPECT_EQ(std::get<0>(tup), 2.0);
    EXPECT_EQ(std::get<1>(tup), 3.0);
    EXPECT_EQ(std::get<2>(tup), 4.0);
    EXPECT_EQ(std::get<0>(tup2), 6.0);
    EXPECT_EQ(std::get<1>(tup2), 7.0);
    EXPECT_EQ(std::get<2>(tup2), 8.0);
}

TEST(TupleApply, ApplyNth)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::apply_nth([](auto& x) { x += 1.0; return x; }, 1, tup);
    EXPECT_EQ(r, 3.0);
    EXPECT_EQ(std::get<0>(tup), 1.0);
    EXPECT_EQ(std::get<1>(tup), 3.0);
    EXPECT_EQ(std::get<2>(tup), 3.0);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



