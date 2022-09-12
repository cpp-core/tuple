// Copyright 2017, 2019, 2021 by Mark Melton
//

#include <gtest/gtest.h>
#include "tuple/list.h"

using namespace core;

TEST(TupleListTest, SelectNth)
{
    auto tup = std::make_tuple(1, 2, 3);
    cout << tp::select_nth(tup, 0) << endl;
    cout << tp::select_nth(tup, 1) << endl;
    cout << tp::select_nth(tup, 2) << endl;
}

TEST(TupleListTest, Test0)
{
    auto tup = std::make_tuple(1,string("abc"),3.0);
    EXPECT_EQ(std::get<0>(tup), 1);
    EXPECT_EQ(std::get<1>(tup), string("abc"));
    EXPECT_EQ(std::get<2>(tup), 3.0);
	
    auto v1 = tp::car(tup);
    EXPECT_EQ(v1, 1);
	
    auto tup23 = tp::cdr(tup);
    EXPECT_EQ(std::get<0>(tup23), string("abc"));
    EXPECT_EQ(std::get<1>(tup23), 3.0);
    
    auto v2 = tp::car(tup23);
    EXPECT_EQ(v2, string("abc"));
    
    auto tup3 = tp::cdr(tup23);
    EXPECT_EQ(std::get<0>(tup3), 3.0);
    
    auto v3 = tp::car(tup3);
    EXPECT_EQ(v3, 3.0);
    
    auto v4 = tp::reverse(tup);
    EXPECT_EQ(v4, std::make_tuple(3,string("abc"),1));
}

TEST(TupleListTest, Test1)
{
    struct sum { int operator()(int s, int v) const { return s + v; }};
    auto tup = std::make_tuple(1,2,3,4);
    auto v1 = tp::rapply(tup, sum(), 0);
    EXPECT_EQ(v1, std::make_tuple(1,3,6,10));
}

TEST(TupleListTest, Test2)
{
    struct product { int operator()(int s, int v) const { return s * v; }};
    auto tup = std::make_tuple(1,2,3,4);
    auto v1 = tp::rapply(tup, product(), 1);
    EXPECT_EQ(v1, std::make_tuple(1,2,6,24));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



