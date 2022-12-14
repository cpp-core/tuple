// Copyright (C) 2017, 2019, 2021, 2022 by Mark Melton
//

#pragma once
#include <cassert>
#include "core/tuple/list_impl.h"

namespace core::tp {

// car, cdr, cons
//
// empty list
//
constexpr const std::tuple<> empty;

/// The nth tuple element.
///
/// \return The nth tuple element.
/// \tparam T The tuple type.
/// \tparam I The tuple index to return.
template<class T, size_t I = 0>
auto& select_nth(T& tup, size_t idx) {
    if (I == idx)
	return std::get<I>(tup);
    if constexpr (I + 1 < std::tuple_size<T>())
		     return select_nth<T,I+1>(tup, idx);
    assert(false);
}

/// A selection of tuple elements
///
/// \return A new tuple containing the tuple elements enumerated by **N**.
/// \tparam T The tuple type.
/// \tparam N The tuple indices to return.
template<typename T, size_t... N>
auto select(const T& t, impl::sequence<N...>)
{ return std::make_tuple(std::get<N>(t)...); }
	
/// The first tuple element.
///
/// \return The first tuple element.
/// \tparam T The tuple type.
template<typename T>
auto car(const T& t)
{ return std::get<0>(t); }

/// All but the first tuple element.
///
/// \return A new tuple with all but the first tuple element from the given tuple.
/// \tparam T The typle type.
template<typename T, typename R = typename impl::range<1, std::tuple_size<T>::value>::type>
auto cdr(const T& t)
{ return select(t, R()); }

/// Create a new tuple by prepending element *x* to tuple *t*.
///
/// \return A new tuple with *x* prepended to *t*.
/// \tparam X The type of the element to prepend.
/// \tparam Xs The types in the tuple *t*.
template<typename X, typename... Xs>
auto cons(X x, const std::tuple<Xs...>& t)
{ return std::tuple_cat(std::make_tuple(x), t); }

/// Create a new tuple by appending element *x* to tuple *t*.
///
/// \return A new tuple with *x* appended to *t*.
/// \tparam X The type of the element to append.
/// \tparam Xs The types in the tuple *t*.
template<typename X, typename... Xs>
auto append(const std::tuple<Xs...>& t, X x)
{ return std::tuple_cat(t, std::make_tuple(x)); }

inline auto reverse(std::tuple<> const& t)
{ return std::tuple<>(); }

/// Reverse the order of the tuple elements.
///
/// \return A new tuple with the tuple element in reverse order.
/// \param t The source tuple.
/// \tparam Xs The tuple element types.
template<typename... Xs>
auto reverse(std::tuple<Xs...> const& t)
{ return append(reverse(cdr(t)), car(t)); }

}; // end ns core::tuple
