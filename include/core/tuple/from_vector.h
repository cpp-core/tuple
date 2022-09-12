// Copyright (C) 2017, 2018, 2019, 2022 by Mark Melton
//

#pragma once

#include <tuple>
#include <functional>

namespace core::tp {

template<typename T, std::size_t... I>
constexpr auto from_vector(std::vector<T>& vec, std::index_sequence<I...>)
{ return std::make_tuple(vec[I]...); }

template<typename T, std::size_t N>
constexpr auto from_vector(std::vector<T>& vec)
{ return from_vector(vec, std::make_index_sequence<N>{}); }

}; // tp

