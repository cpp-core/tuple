// Copyright (C) 2017, 2019, 2021, 2022 by Mark Melton
//

#ifndef CORE_TUPLE_APPLY_H
#define CORE_TUPLE_APPLY_H

#include "core/mp/meta.h"
#include "core/tuple/util.h"

namespace core::tp {

/// Updates `tuple` by calling `function` on each member in turn.
///
/// There must exist an overload of `function` for each member of tuple
/// passed as a single argument.
template<typename F, typename T, typename Indices = make_tuple_index<T>>
void apply(F&& function, T& tuple)
{
    return mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	(function(std::get<Is>(tuple)),...);
    });
}

/// Updates `tuples` by calling `function` on each set of members in
/// turn. I.e., `function` is invoked first with the `n` first members
/// of each tuple in `tuples`, and then the second with the `n` second
/// members, etc.
///
/// There must exist an overload of `function` for each set of tuple
/// members.
///
/// Every tuple in `tuple` must be of the same arity.
template<class F, class... Ts, class Indices = make_tuple_index<nth<0,Ts...>>>
void apply_n(F&& function, Ts&... tuples) {
    auto get_element = [&](auto I) { return function(std::get<I>(tuples)...); };
    mp::invoke_with_pack(Indices{}, [&](auto... Is) {
	(get_element(Is),...);
    });
}

/// Returns the result of calling `function` on the `n`'th member of
/// `tuple`.
///
template<size_t I = 0, class Function, class Tuple>
auto apply_nth(Function&& function, size_t n, Tuple& tuple)
{
    if (I == n) return function(std::get<I>(tuple));
    else if constexpr (I + 1 < std::tuple_size_v<Tuple>) return apply_nth<I+1>(function, n, tuple);
    throw std::runtime_error("apply_nth: index out of range");
}

}; // end namespace tuple

#endif
