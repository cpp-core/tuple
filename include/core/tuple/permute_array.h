// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include <array>
#include <tuple>
#include <functional>
#include "core/util/common.h"
#include "core/mp/permutation.h"

namespace core::tp
{

namespace detail
{
template<typename T, typename... Is>
auto impl(T const& array, core::mp::list<Is...>)
{ return std::array<typename T::value_type, sizeof...(Is)>{{ std::get<Is::value>(array)... }}; }
};

template<typename S, typename T, typename U>
auto permute_array(U const& array)
{
    using Index = core::mp::permutation_t<S,T>;
    return detail::impl(array, Index{});
}

}; // tp
