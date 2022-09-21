// Copyright 2017, 2019, 2021, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/tuple/compare.h"

using namespace core;

TEST(TupleCompare, Equal)
{
    auto tup1 = std::make_tuple(1.0, 2.0, 3.0);
    auto tup2 = std::make_tuple(1.0, 2.0, 4.0);
    auto r = tp::equal(tup1, tup2);
    EXPECT_EQ(r, std::make_tuple(true,true,false));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



