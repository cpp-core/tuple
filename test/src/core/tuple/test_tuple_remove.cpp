// Copyright 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/tuple/remove.h"

using namespace core;

TEST(TupleApply, Test0)
{
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    {
	auto sup = tp::remove<0>(tup);
	EXPECT_EQ(sup, std::make_tuple(2.0,3.0));
    }
    {
	auto sup = tp::remove<1>(tup);
	EXPECT_EQ(sup, std::make_tuple(1.0,3.0));
    }
    {
	auto sup = tp::remove<2>(tup);
	EXPECT_EQ(sup, std::make_tuple(1.0,2.0));
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



