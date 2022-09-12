// Copyright 2017, 2019, 2020, 2021, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/tuple/to_container.h"
#include "core/mp/homogeneous.h"

using namespace core;

TEST(TupleToArray, SizeT)
{
    auto tup = std::make_tuple(0u, 1u, 2u, 3u, 4u);
    auto arr = tp::to_container<std::vector<uint>>(tup);
    EXPECT_EQ(arr.size(), 5);
    EXPECT_EQ(arr[0], 0u);
    EXPECT_EQ(arr[1], 1u);
    EXPECT_EQ(arr[2], 2u);
    EXPECT_EQ(arr[3], 3u);
    EXPECT_EQ(arr[4], 4u);
}

TEST(TupleToArray, Float)
{
    auto tup = std::make_tuple(0.5, 1.5, 2.5);
    auto arr = tp::to_container<std::vector<double>>(tup);
    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr[0], 0.5);
    EXPECT_EQ(arr[1], 1.5);
    EXPECT_EQ(arr[2], 2.5);
}

TEST(TupleToArray, Mixed)
{
    // The following should trigger a static assertion
    // auto tup = std::make_tuple("zero"s, 1.5, 2.5);
    // auto arr = tp::to_vector(tup);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



