// Copyright 2017, 2019, 2021, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/tuple/list.h"

using namespace core;

TEST(TupleListTest, SelectNth)
{
    auto tup = std::make_tuple(1, 2, 3);
    std::cout << tp::select_nth(tup, 0) << std::endl;
    std::cout << tp::select_nth(tup, 1) << std::endl;
    std::cout << tp::select_nth(tup, 2) << std::endl;
}

TEST(TupleListTest, Test0)
{
    auto tup = std::make_tuple(1,std::string("abc"),3.0);
    EXPECT_EQ(std::get<0>(tup), 1);
    EXPECT_EQ(std::get<1>(tup), std::string("abc"));
    EXPECT_EQ(std::get<2>(tup), 3.0);
	
    auto v1 = tp::car(tup);
    EXPECT_EQ(v1, 1);
	
    auto tup23 = tp::cdr(tup);
    EXPECT_EQ(std::get<0>(tup23), std::string("abc"));
    EXPECT_EQ(std::get<1>(tup23), 3.0);
    
    auto v2 = tp::car(tup23);
    EXPECT_EQ(v2, std::string("abc"));
    
    auto tup3 = tp::cdr(tup23);
    EXPECT_EQ(std::get<0>(tup3), 3.0);
    
    auto v3 = tp::car(tup3);
    EXPECT_EQ(v3, 3.0);
    
    auto v4 = tp::reverse(tup);
    EXPECT_EQ(v4, std::make_tuple(3,std::string("abc"),1));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



