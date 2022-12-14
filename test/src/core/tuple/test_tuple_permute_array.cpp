// Copyright 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/tuple/permute_array.h"
#include "core/mp/list.h"
#include "core/mp/constants.h"

using namespace core;

TEST(TuplePermuteArray, NtoN)
{
    using S = mp::list<mp_a,mp_b,mp_c>;
    using T = mp::list<mp_b,mp_c,mp_a>;
    auto arr = std::array<size_t,3>{{ 1, 2, 3 }};
    auto new_arr = tp::permute_array<S,T>(arr);
    EXPECT_EQ(new_arr[0], arr[1]);
    EXPECT_EQ(new_arr[1], arr[2]);
    EXPECT_EQ(new_arr[2], arr[0]);
}

TEST(TuplePermuteArray, NtoM)
{
    using S = mp::list<mp_a,mp_b,mp_c>;
    using T = mp::list<mp_b,mp_a,mp_a>;
    auto arr = std::array<size_t,3>{{ 1, 2, 3 }};
    auto new_arr = tp::permute_array<S,T>(arr);
    EXPECT_EQ(new_arr[0], arr[1]);
    EXPECT_EQ(new_arr[1], arr[0]);
    EXPECT_EQ(new_arr[2], arr[0]);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



