// Copyright (C) 2021, 2022 by Mark Melton
//

#pragma once
#include <tuple>
#include <functional>
#include "core/mp/homogeneous.h"

namespace core::tp
{

template<class C, class T, std::size_t... Indices>
constexpr auto to_container(T&& tup, std::index_sequence<Indices...>)
{
    static_assert(core::mp::homogeneous_v<std::decay_t<T>>,
		  "\n\nSTATIC ASSERTION FAILURE\n"
		  "core::mp::to_tensor requires a homogeneous tuple type\n\n");
    return C{{ std::forward<typename C::value_type>(std::get<Indices>(std::forward<T>(tup)))... }};
}

template<class C, class T>
constexpr auto to_container(T&& tup)
{
    return to_container<C,T>(std::forward<T>(tup),
			     std::make_index_sequence<std::tuple_size_v<std::decay_t<T>>>{});
}

}; // tp
