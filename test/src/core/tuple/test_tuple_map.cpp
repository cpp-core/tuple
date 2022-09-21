// Copyright 2017, 2019, 2021, 2022 by Mark Melton
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

TEST(TupleMap, MapTwoTuples)
{
    auto tup1 = std::make_tuple(1.0, 2.0, 3.0);
    auto tup2 = std::make_tuple(0.0, 1.0, 2.0);
    auto r = tp::map([](auto x, auto y) { return x - y; }, tup1, tup2);
    EXPECT_EQ(r, std::make_tuple(1.0, 1.0, 1.0));
}

TEST(TupleMap, MapInplace)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    tp::map_inplace([](auto& x) { x += 1.0; }, tup);
    EXPECT_EQ(std::get<0>(tup), 2.0);
    EXPECT_EQ(std::get<1>(tup), 3.0);
    EXPECT_EQ(std::get<2>(tup), 4.0);
}

TEST(TupleMap, MapInplaceTwoTuples)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto tup2 = std::make_tuple(4.0, 5.0, 6.0);
    tp::map_inplace([](auto& x, auto& y) { x += 1.0; y += 2.0; }, tup, tup2);
    EXPECT_EQ(std::get<0>(tup), 2.0);
    EXPECT_EQ(std::get<1>(tup), 3.0);
    EXPECT_EQ(std::get<2>(tup), 4.0);
    EXPECT_EQ(std::get<0>(tup2), 6.0);
    EXPECT_EQ(std::get<1>(tup2), 7.0);
    EXPECT_EQ(std::get<2>(tup2), 8.0);
}

TEST(TupleMap, MapInplaceAndReturnTuple)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::map_inplace([](auto& x) { x += 1; return x; }, tup);
    EXPECT_EQ(tup, std::make_tuple(2.0, 3.0, 4.0));
    EXPECT_EQ(r, std::make_tuple(2.0, 3.0, 4.0));
}

TEST(TupleMap, MapWithStateSum)
{
    struct sum { int operator()(int s, int v) const { return s + v; }};
    auto tup = std::make_tuple(1,2,3,4);
    auto v1 = tp::map(tup, sum(), 0);
    EXPECT_EQ(v1, std::make_tuple(1,3,6,10));
}

TEST(TupleMap, MapWithStateProduct)
{
    struct product { int operator()(int s, int v) const { return s * v; }};
    auto tup = std::make_tuple(1,2,3,4);
    auto v1 = tp::map(tup, product(), 1);
    EXPECT_EQ(v1, std::make_tuple(1,2,6,24));
}

TEST(TupleMap, MapNth)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::map_nth([](auto& x) { x += 1.0; return x; }, 1, tup);
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



