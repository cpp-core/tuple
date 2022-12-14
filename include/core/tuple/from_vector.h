// Copyright (C) 2017, 2018, 2019, 2022 by Mark Melton
//

#pragma once

#include <tuple>
#include <functional>

namespace core::tp {

template<typename T, std::size_t... I>
constexpr auto from_vector(std::vector<T>& vec, std::index_sequence<I...>)
{ return std::make_tuple(vec[I]...); }

/// Create a new tuple from the given vector *vec*.
///
/// The template parameter **N** must be supplied by the caller
/// because it cannot be inferred from the vector at compile
/// time.
///
/// \returns A new tuple with the elements from vector *vec*.
/// \tparam T The vector element type.
/// \tparam N The size of the container.
template<typename T, std::size_t N>
constexpr auto from_vector(std::vector<T>& vec)
{ return from_vector(vec, std::make_index_sequence<N>{}); }

}; // tp

