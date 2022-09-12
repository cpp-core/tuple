// Copyright 2017, 2018, 2019, 2021 by Mark Melton
//

#include <gtest/gtest.h>
#include "tuple/from_container.h"

using namespace core;

TEST(TupleFromContainer, Test0)
{
    std::vector<size_t> A = { 0, 1, 2, 3, 4 };
    auto tup = tp::from_container<5>(A);
    EXPECT_EQ(std::get<0>(tup), 0u);
    EXPECT_EQ(std::get<1>(tup), 1u);
    EXPECT_EQ(std::get<2>(tup), 2u);
    EXPECT_EQ(std::get<3>(tup), 3u);
    EXPECT_EQ(std::get<4>(tup), 4u);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



