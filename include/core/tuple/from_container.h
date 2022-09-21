// Copyright (C) 2021, 2022 by Mark Melton
//

#pragma once

#include <tuple>
#include <functional>

namespace core::tp {

template<class C, std::size_t... I>
constexpr auto from_container(const C& c, std::index_sequence<I...>)
{ return std::make_tuple(c[I]...); }

/// Create a new tuple from the given container *c*.
///
/// The template parameter **N** must be supplied by the caller
/// because it cannot, in general, be inferred from the container at
/// compile time. Also, the container *C* must have an indexing
/// operator[].
///
/// \returns A new tuple with the elements from container *c*.
/// \tparam N The size of the container.
/// \tparam T The container element type.
template<std::size_t N, class C>
constexpr auto from_container(const C& c)
{ return from_container(c, std::make_index_sequence<N>{}); }

}; // tp

