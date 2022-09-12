// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#ifndef CORE_TUPLE_MAP_H
#define CORE_TUPLE_MAP_H

#include <tuple>
#include <functional>
#include "core/mp/meta.h"
#include "core/tuple/util.h"
#include "core/tuple/list.h"

namespace core::tp {

using namespace core;

// map -- Map <function> over <tuple> returning
// std::tuple<function(std::get<0>(tuple)),
//            function(std::get<1>(tuple)),
//            ...>
//
template<typename F, typename T, typename Indices = make_tuple_index<T>>
auto map(F&& function, T const& tuple) 
{
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	    return std::make_tuple(function(std::get<Is>(tuple))...);
	});
}

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

// map_n -- Map <function> over <tuples> t0,t1,... returning
// std::tuple<function(std::get<0>(t0), std::get<0>(t1),...),
//            function(std::get<1>(t0), std::get<1>(t1),...),
//            ...>
//
template<typename F,
	 typename... Ts,
	 typename Indices = make_tuple_index<nth<0,Ts...>>>
auto map_n(F&& function, Ts&... tuples)
{
    auto get_element = [&](auto I) { return function(std::get<I>(tuples)...); };
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	    return std::make_tuple(get_element(Is)...);
	});
}

// fold left
//
template<typename F, typename V, typename T, typename Indices = make_tuple_index<T>>
auto fold_l(F&& function, V value, T const& tuple)
{
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	    ((value = function(value, std::get<Is>(tuple))),...);
	    return value;
	});
}

// fold right
//
template<typename F, typename V, typename T, typename Indices = make_tuple_index<T>>
auto fold_r(F&& function, V value, T const& tuple)
{
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	    ((value = function(value, std::get<Indices::size()-Is-1>(tuple))),...);
	    return value;
	});
}

// compare
//
template<typename T, typename U>
auto compare(T& a, U& b)
{ return map_n([](auto const& aelem, auto const& belem) { return aelem == belem; }, a, b); }

// min
//
template<typename T, typename... Ts>
auto min(std::tuple<T,Ts...> const& tuple)
{
    auto r = std::get<0>(tuple);
    return fold_l([](auto a, auto b) { return a <= b ? a : b; }, r, cdr(tuple));
}

// max
//
template<typename T, typename... Ts>
auto max(std::tuple<T,Ts...> const& tuple)
{
    auto r = std::get<0>(tuple);
    return fold_l([](auto a, auto b) { return a >= b ? a : b; }, r, cdr(tuple));
}

// bool reduction
//
// any
//
template<typename... Ts>
auto any(std::tuple<Ts...> const& tuple)
{
    static_assert((std::is_convertible<Ts,bool>::value && ...),
		  "Tuple elements must be convertible to bool");
    return fold_l([](auto a, auto b) { return a or b; }, false, tuple);
}

// all
//
template<typename... Ts>
auto all(std::tuple<Ts...> const& tuple)
{
    static_assert((std::is_convertible<Ts,bool>::value && ...),
		  "Tuple elements must be convertible to bool");
    return fold_l([](auto a, auto b) { return a and b; }, true, tuple);
}

// none
//
template<typename... Ts>
auto none(std::tuple<Ts...> const& tuple)
{ return not any(tuple); }

}; // tuple

#endif
