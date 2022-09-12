// Copyright 2017, 2019, 2021 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/tuple/map.h"

using namespace core;

TEST(TupleMap, Map)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::map([](auto x) { return x + 1.0; }, tup);
    EXPECT_EQ(r, std::make_tuple(2.0, 3.0, 4.0));
}

TEST(TupleMap, Mapply)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::mapply([](auto& x) { x += 1; return x; }, tup);
    EXPECT_EQ(tup, std::make_tuple(2.0, 3.0, 4.0));
    EXPECT_EQ(r, std::make_tuple(2.0, 3.0, 4.0));
}

TEST(TupleMap, MapN)
{
    auto tup1 = std::make_tuple(1.0, 2.0, 3.0);
    auto tup2 = std::make_tuple(0.0, 1.0, 2.0);
    auto r = tp::map_n([](auto x, auto y) { return x - y; }, tup1, tup2);
    EXPECT_EQ(r, std::make_tuple(1.0, 1.0, 1.0));
}

TEST(TupleMap, FoldL)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::fold_l([](auto x, auto y) { return x - y; }, 7.0, tup);
    EXPECT_EQ(r, 1.0);
}

TEST(TupleMap, FoldR)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::fold_r([](auto x, auto y) { return x - y; }, 7.0, tup);
    EXPECT_EQ(r, 1.0);
}

TEST(TupleMap, Compare)
{
    auto tup1 = std::make_tuple(1.0, 2.0, 3.0);
    auto tup2 = std::make_tuple(1.0, 2.0, 4.0);
    auto r = tp::compare(tup1, tup2);
    EXPECT_EQ(r, std::make_tuple(true,true,false));
}

TEST(TupleMap, AnyFalse)
{
    auto tup1 = std::make_tuple(false, false, false);
    auto r = tp::any(tup1);
    EXPECT_EQ(r, false);
}

TEST(TupleMap, AnyTrue)
{
    auto tup1 = std::make_tuple(false, true, false);
    auto r = tp::any(tup1);
    EXPECT_EQ(r, true);
}

TEST(TupleMap, AllFalse)
{
    auto tup1 = std::make_tuple(false, true, true);
    auto r = tp::all(tup1);
    EXPECT_EQ(r, false);
}

TEST(TupleMap, AllTrue)
{
    auto tup1 = std::make_tuple(true, true, true);
    auto r = tp::all(tup1);
    EXPECT_EQ(r, true);
}

TEST(TupleMap, NoneTrue)
{
    auto tup1 = std::make_tuple(false, false, false);
    auto r = tp::none(tup1);
    EXPECT_EQ(r, true);
}

TEST(TupleMap, NoneFalse)
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



