// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#ifndef CORE_TUPLE_UTIL_H
#define CORE_TUPLE_UTIL_H

#include <tuple>
#include <functional>

namespace core::tp {

// nth -- Helper template for computing type of nth parameter pack
// element.
template<size_t N, typename... Ts>
using nth = typename std::tuple_element<N, std::tuple<Ts...>>::type;

// make_tuple_index -- Helper template for computing indices
// corresponding to a tuple.
//
template<typename T>
using make_tuple_index = std::make_index_sequence<std::tuple_size<T>::value>;

}; // tp

#endif
