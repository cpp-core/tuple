// Copyright 2016, 2019, 2022 by Mark Melton. All rights reserved.
//

#include <gtest/gtest.h>
#include <sstream>
#include "core/tuple/print.h"

using namespace core;

TEST(TuplePrint, Test0)
{
    auto tup = std::make_tuple(1, std::string("abc"),3.0);
    std::stringstream ss;
    ss << tup;
    EXPECT_EQ(ss.str(), "1,abc,3");
}

TEST(TuplePrint, Test1)
{
    auto tup = std::make_tuple(1, std::string("abc"),3.0);
    std::stringstream ss;
    tp::print(ss, tup);
    EXPECT_EQ(ss.str(), "1,abc,3");
}

TEST(TuplePrint, Test2)
{
    auto tup = std::make_tuple(1, std::string("abc"),3.0);
    std::stringstream ss;
    tp::print(ss, tup, ":");
    EXPECT_EQ(ss.str(), "1:abc:3");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

