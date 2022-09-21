// Copyright (C) 2019, 2022 by Mark Melton
//

#pragma once
#include <tuple>

namespace core::tp {

/// Find the first tuple element that satisfies the given *predicate*.
///
/// \return The index of the first tuple element that satisfies *predicate*, or -1.
/// \tparam I The starting tuple index
/// \tparam Tuple The tuple type.
/// \tparam Predicate The predicate type.
template<size_t I = 0, class Tuple, class Predicate>
std::ptrdiff_t find_first(const Tuple& tup, Predicate predicate)
{
    if constexpr (I == std::tuple_size_v<Tuple>) return -1;
    else if (predicate(std::get<I>(tup))) return I;
    else return find_first<I+1>(tup, predicate);
}

}; // core::tp
