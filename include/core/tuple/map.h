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
auto map_inplace(F&& function, Ts&... tuples) {
    auto get_element = [&](auto I) { return function(std::get<I>(tuples)...); };
    using I0 = std::integral_constant<size_t, 0>;
    constexpr auto void_return = std::is_same_v<decltype(get_element(I0{})), void>;
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	if constexpr (void_return) {
	    (get_element(Is), ...);
	} else {
	    return std::make_tuple(get_element(Is)...);
	}
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

template<typename F, typename T, typename Indices = make_tuple_index<T>>
auto map_ref(F&& function, T const& tuple)
{
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	    return std::forward_as_tuple(function(std::get<Is>(tuple))...);
	});
}

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
    state = function(state, car(tuple));
    if constexpr (std::tuple_size_v<std::tuple<Ts...>> == 1)
	return std::make_tuple(state);
    else
	return cons(state, map(cdr(tuple), function, state));
}

}; // tuple
