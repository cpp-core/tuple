// Copyright 2018, 2019, 2021 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/tuple/parse.h"

using namespace core;

TEST(TupleParse, Test0)
{
    using type = std::tuple<int,string,float>;
    auto views = string_views{ "1", "abc", "1.25" };
    auto tup = tp::parse<type>(views);
    EXPECT_EQ(std::get<0>(tup), 1);
    EXPECT_EQ(std::get<1>(tup), "abc");
    EXPECT_EQ(std::get<2>(tup), 1.25);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



