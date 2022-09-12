// Copyright (C) 2017, 2019, 2020, 2022 by Mark Melton
//

#pragma once
#include <array>
#include <tuple>
#include <functional>
#include "core/mp/homogeneous.h"

namespace core::tp
{

template<typename T, std::size_t... Indices>
constexpr auto to_vector(T&& tup, std::index_sequence<Indices...>)
{
    static_assert(core::mp::homogeneous_v<std::decay_t<T>>,
		  "\n\nSTATIC ASSERTION FAILURE\n"
		  "core::mp::to_vector requires a homogeneous tuple type\n\n");
    using return_type = typename std::tuple_element<0, std::decay_t<T>>::type;
    return std::vector<return_type>
	{{ std::forward<return_type>(std::get<Indices>(std::forward<T>(tup)))... }};
}

template<typename T>
constexpr auto to_vector(T&& tup)
{
    return to_vector(std::forward<T>(tup),
		    std::make_index_sequence<std::tuple_size_v<std::decay_t<T>>>{});
}

}; // tp
