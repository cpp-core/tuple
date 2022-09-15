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

// nth
//
template<class T, size_t I = 0>
auto& select_nth(T& tup, size_t idx) {
    if (I == idx)
	return std::get<I>(tup);
    if constexpr (I + 1 < std::tuple_size<T>())
		     return select_nth<T,I+1>(tup, idx);
    assert(false);
}

// select
//
template<typename T, size_t... N>
auto select(const T& t, impl::sequence<N...>)
{ return std::make_tuple(std::get<N>(t)...); }
	
// car
//
template<typename T>
auto car(const T& t)
{ return std::get<0>(t); }

// cdr
//
template<typename T, typename R = typename impl::range<1, std::tuple_size<T>::value>::type>
auto cdr(const T& t)
{ return select(t, R()); }

// cons
//
template<typename X, typename... Xs>
auto cons(X x, const std::tuple<Xs...>& t)
{ return std::tuple_cat(std::make_tuple(x), t); }

// append
//
template<typename X, typename... Xs>
auto append(const std::tuple<Xs...>& t, X x)
{ return std::tuple_cat(t, std::make_tuple(x)); }

// reverse
//
inline auto reverse(std::tuple<> const& t)
{ return std::tuple<>(); }

template<typename... Xs>
auto reverse(std::tuple<Xs...> const& t)
{ return append(reverse(cdr(t)), car(t)); }

// rapply
//
template<typename OP, typename T>
auto rapply(std::tuple<> const& t, OP&&, T)
{ return std::tuple<>(); }
    
template<typename OP, typename T, typename... Xs>
auto rapply(std::tuple<Xs...> const& t, OP&& op, T state)
{
    state = op(state,car(t));
    return cons(state, rapply(cdr(t), op, state));
}

}; // end ns core::tuple
