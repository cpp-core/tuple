// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#ifndef CORE_TUPLE_MATH_H
#define CORE_TUPLE_MATH_H

#include <tuple>
#include <functional>

namespace core::tp
{

template<size_t D, typename T, typename U>
struct dot_product_impl
{
    static auto apply(T const& tup, U const& sup)
    {
	size_t p = std::get<D>(tup) * std::get<D>(sup);
	if constexpr (D > 0) return p + dot_product_impl<D-1,T,U>::apply(tup,sup);
	else return p;
    }
};
    
template<typename T, typename U>
auto dot_product(T const& tup, U const& sup)
{
    static_assert(std::tuple_size_v<T> == std::tuple_size_v<U>,
		  "dot_product: tuples must be the same size");
    if constexpr (std::tuple_size_v<T> == 0) return 0;
    return dot_product_impl<std::tuple_size_v<T>-1,T,U>::apply(tup,sup);
}

}; // tp
    
#endif
