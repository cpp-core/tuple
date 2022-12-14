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

/// Left fold **function** over the elements of **tuple** starting with the
/// given initial **value**.
///
/// \result The result of left folding **function** of the **tuple** elements start with **value**.
/// \param function The function to left fold across the **tuple** elements.
/// \param value The initial value of the fold.
/// \param tuple The source tuple.
/// \tparam F The function type.
/// \tparam V The initial value type.
/// \tparam T The tuple type.
template<typename F, typename V, typename T, typename Indices = make_tuple_index<T>>
auto fold_l(F&& function, V value, T const& tuple)
{
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	    ((value = function(value, std::get<Is>(tuple))),...);
	    return value;
	});
}

/// Right fold **function** over the elements of **tuple** starting with the
/// given initial **value**.
///
/// \result The result of right folding **function** of the **tuple** elements start with **value**.
/// \param function The function to right fold across the **tuple** elements.
/// \param value The initial value of the fold.
/// \param tuple The source tuple.
/// \tparam F The function type.
/// \tparam V The initial value type.
/// \tparam T The tuple type.
template<typename F, typename V, typename T, typename Indices = make_tuple_index<T>>
auto fold_r(F&& function, V value, T const& tuple)
{
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	    ((value = function(value, std::get<Indices::size()-Is-1>(tuple))),...);
	    return value;
	});
}

/// The minimum tuple element.
///
/// \return The minimum tuple element.
/// \tparam T The type of the first tuple element.
/// \tparam Ts The types of the remaining tuple elements.
template<typename T, typename... Ts>
auto min(std::tuple<T,Ts...> const& tuple)
{
    auto r = std::get<0>(tuple);
    return fold_l([](auto a, auto b) { return a <= b ? a : b; }, r, cdr(tuple));
}

/// The maximum tuple element.
///
/// \return The maximum tuple element.
/// \tparam T The type of the first tuple element.
/// \tparam Ts The types of the remaining tuple elements.
template<typename T, typename... Ts>
auto max(std::tuple<T,Ts...> const& tuple)
{
    auto r = std::get<0>(tuple);
    return fold_l([](auto a, auto b) { return a >= b ? a : b; }, r, cdr(tuple));
}

/// True if any tuple elements are true; otherwise, false.
///
/// \return True if any tuple elements are true; otherwise, false.
/// \param tuple The source tuple.
/// \tparam Ts The types of the tuple elements. Must be bool convertible.
template<typename... Ts>
auto any(std::tuple<Ts...> const& tuple)
{
    static_assert((std::is_convertible<Ts,bool>::value && ...),
		  "Tuple elements must be convertible to bool");
    return fold_l([](auto a, auto b) { return a or b; }, false, tuple);
}

/// True if all tuple elements are true; otherwise, false.
///
/// \return True if all tuple elements are true; otherwise, false.
/// \param tuple The source tuple.
/// \tparam Ts The types of the tuple elements. Must be bool convertible.
template<typename... Ts>
auto all(std::tuple<Ts...> const& tuple)
{
    static_assert((std::is_convertible<Ts,bool>::value && ...),
		  "Tuple elements must be convertible to bool");
    return fold_l([](auto a, auto b) { return a and b; }, true, tuple);
}

/// True if none of the tuple elements are true; otherwise, false.
///
/// \return True if none of the tuple elements are true; otherwise, false.
/// \param tuple The source tuple.
/// \tparam Ts The types of the tuple elemetns. Must be bool convertible.
template<typename... Ts>
auto none(std::tuple<Ts...> const& tuple)
{ return not any(tuple); }

}; // tuple
