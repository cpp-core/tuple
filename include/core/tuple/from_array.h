// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include <array>
#include <tuple>
#include <functional>

namespace core::tp {

template<typename T, std::size_t... I, std::size_t N>
constexpr auto from_array(std::array<T,N>& array, std::index_sequence<I...>)
{ return std::make_tuple(array[I]...); }

template<typename T, std::size_t N>
constexpr auto from_array(std::array<T,N>& array)
{ return from_array(array, std::make_index_sequence<N>{}); }

}; // core::tp
