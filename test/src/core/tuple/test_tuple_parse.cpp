// Copyright 2018, 2019, 2021, 2022 by Mark Melton
//

#include <gtest/gtest.h>

namespace core::str {

namespace detail {
template<class T>
struct lexical_cast_impl;

template<>
struct lexical_cast_impl<std::string> {
    static std::string parse(std::string_view input) {
	return std::string(input);
    }
};

template<>
struct lexical_cast_impl<int> {
    static int parse(std::string_view input) {
	return std::atoi(input.data());
    }
};

template<>
struct lexical_cast_impl<float> {
    static float parse(std::string_view input) {
	return std::atof(input.data());
    }
};

}; // detail

template<class T, class... Us>
T lexical_cast(std::string_view s, Us... extra)
{ return detail::lexical_cast_impl<T>::parse(s, extra...); }

}; // core::str


#include "core/tuple/parse.h"

using namespace core;

TEST(TupleParse, Test0)
{
    using type = std::tuple<int,std::string,float>;
    auto views = std::vector<std::string_view>{ "1", "abc", "1.25" };
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



