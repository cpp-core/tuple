// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#ifndef CORE_TUPLE_REMOVE_H
#define CORE_TUPLE_REMOVE_H

#include <tuple>
#include <functional>

namespace core::tp {

constexpr auto map_seq_rm(std::size_t idx, std::size_t rdx)
{ return idx < rdx ? idx : idx + 1; }

template<size_t Idx, typename... Ts, std::size_t... Is>
auto remove_impl(const std::tuple<Ts...>& t, std::index_sequence<Is...>) {
    return std::make_tuple(std::get<map_seq_rm(Is,Idx)>(t)...);
}

template<size_t Idx, typename... Ts>
auto remove(std::tuple<Ts...> const& tup) {
    return remove_impl<Idx>(tup, std::make_index_sequence<sizeof...(Ts) - 1>{});
}

}; // tp

#endif
