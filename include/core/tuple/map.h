// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once

#include <tuple>
#include <functional>
#include "core/mp/meta.h"
#include "core/tuple/util.h"
#include "core/tuple/list.h"

namespace core::tp {

using namespace core;

/// Map **function** across each stripe of elements in *tuples*.
///
/// The given **function** is first invoked across the first element
/// of each tuple, i.e. `function(std::get<0>(tuple0),
/// std::get<0>(tuple1), ...)` to produce the first element of the new
/// tuple. And, then, on each successive stripe of elements.
///
/// \return A new tuple resulting from mapping **function** across each stripe of elements.
/// param function The function to map across the given **tuples**.
/// param tuples The tuples to map across.
/// \tparam F The function type.
/// \tparam Ts The tuple types.
template<typename F, typename... Ts, typename Indices = make_tuple_index<nth<0,Ts...>>>
auto map(F&& function, const Ts&... tuples)
{
    auto get_element = [&](auto I) { return function(std::get<I>(tuples)...); };
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	    return std::make_tuple(get_element(Is)...);
	});
}

/// Map **function** on each element of **tuple**.
///
/// \return A new tuple with the result of mapping **function** on each element of **tuple**.
/// \param function The function to invoke on each element of **tuple**.
/// \param tuple The source tuple.
/// \tparam F The function type
/// \tparam T The tuple type.
// template<typename F, typename T, typename Indices = make_tuple_index<T>>
// auto map(F&& function, T const& tuple) 
// {
//     return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
// 	    return std::make_tuple(function(std::get<Is>(tuple))...);
// 	});
// }

/// Modify *tuples* inplace by invoking *function* sequentially on
/// each stripe of tuple elements.
///
/// The given *function* is first invoked on the first element of each
/// tuple, i.e. `function(std::get<0>(tuple0), std::get<0>(tuple1),
/// ...)`. And, then on each successive set of elements.
///
/// \param function The function to map across the stripes of tuple elements.
/// \param tuples The tuples to modify in place.
/// \tparam F The function type.
/// \tparam Ts The tuple types.
template<class F, class... Ts, class Indices = make_tuple_index<nth<0,Ts...>>>
void map_inplace(F&& function, Ts&... tuples) {
    auto get_element = [&](auto I) { return function(std::get<I>(tuples)...); };
    mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	(get_element(Is), ...);
    });
}

/// Invoke *function* on the *n*'th element of *tuple*.
///
/// \return The result of *function* applied to the *n*'th element of *tuple*.
/// \tparam I The tuple index to operate on.
/// \tparam Function The function type.
/// \tparam Tuple The tuple type.
template<size_t I = 0, class Function, class Tuple>
auto map_nth(Function&& function, size_t n, Tuple& tuple)
{
    if (I == n) return function(std::get<I>(tuple));
    else if constexpr (I + 1 < std::tuple_size_v<Tuple>) return map_nth<I+1>(function, n, tuple);
    throw std::runtime_error("apply_nth: index out of range");
}

/// Map/Apply **function** on/to each element of **tuple** possibly
/// modifying **tuple** inplace.
///
/// \return A new tuple with the result of mapping **function** on each element of **tuple**.
/// \param function The function to invoke on each element of **tuple**.
/// \param tuple The source tuple.
/// \tparam F The function type
/// \tparam T The tuple type.
template<typename F, typename T, typename Indices = make_tuple_index<T>>
auto mapply(F&& function, T& tuple) 
{
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	    return std::make_tuple(function(std::get<Is>(tuple))...);
	});
}

template<typename F, typename T, typename Indices = make_tuple_index<T>>
auto map_ref(F&& function, T const& tuple)
{
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	    return std::forward_as_tuple(function(std::get<Is>(tuple))...);
	});
}


template<typename F, typename S>
auto map(std::tuple<> const& tuple, F&&, S)
{ return std::tuple<>(); }

/// Map **function** sequentially to each element of **tuple** passing along **state**.
///
/// \return A new tuple resulting from mapping **function** across each element.
/// \param tuple The source tuple.
/// \param function The function to apply.
/// \param state The initial state.
/// \tparam F The function type.
/// \tparam S The state type.
/// \tparam Ts. The tuple element types.
template<typename F, typename S, typename... Ts>
auto map(std::tuple<Ts...> const& tuple, F&& function, S state)
{
    state = function(state,car(tuple));
    return cons(state, map(cdr(tuple), function, state));
}

/// Equality comparison for tuples *a* and *b*.
///
/// \return True if all the corresponding elements of *a* and *b* compare equal.
/// \tparam T The type of the first tuple.
/// \tparam U The type of the second tuple.
template<typename T, typename U>
auto compare(T& a, U& b)
{ return map([](auto const& aelem, auto const& belem) { return aelem == belem; }, a, b); }

}; // tuple
