// Copyright (C) 2021, 2022 by Mark Melton
//

#pragma once

#include <tuple>
#include <functional>
#include "core/util/common.h"

namespace core::tp {

template<class C, std::size_t... I>
constexpr auto from_container(const C& c, std::index_sequence<I...>)
{ return std::make_tuple(c[I]...); }

template<std::size_t N, class C>
constexpr auto from_container(const C& c)
{ return from_container(c, std::make_index_sequence<N>{}); }

}; // tp

