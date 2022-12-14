// Copyright 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/tuple/permute.h"
#include "core/mp/list.h"
#include "core/mp/constants.h"

using namespace core;

TEST(TuplePermute, Test0)
{
    using L1 = mp::list<mp_a,mp_b,mp_c>;
    using L2 = mp::list<mp_c,mp_b>;
    auto tup = std::make_tuple(1.0, 2.0, 3.0);
    auto r = tp::permute<L1,L2>(tup);
    EXPECT_EQ(r, std::make_tuple(3.0, 2.0));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



