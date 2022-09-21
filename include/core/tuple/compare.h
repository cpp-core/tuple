// Copyright (C) 2022 by Mark Melton
//

#pragma once
#include "core/tuple/map.h"

namespace core::tp {

/// Elementwise equality comparison for tuples **a** and **b**.
///
/// \return A new tuple with the results of comparing each element of **a** and **b**.
/// \tparam T The type of the first tuple.
/// \tparam U The type of the second tuple.
template<typename T, typename U>
auto equal(T& a, U& b) {
    static_assert(std::tuple_size_v<T> == std::tuple_size_v<U>,
		  "Cannot compare tuples of different arity for elementwise equality.");
    return map([](auto const& aelem, auto const& belem) {
	return aelem == belem;
    }, a, b);
}

}; // core::tp
