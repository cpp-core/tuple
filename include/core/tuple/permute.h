// Copyright (C) 2017, 2019 by Mark Melton
//

#ifndef CORE_TUPLE_PERMUTE_H
#define CORE_TUPLE_PERMUTE_H

#include <tuple>
#include <functional>
#include "core/mp/list.h"
#include "core/mp/permutation.h"
#include "core/mp/generate.h"
#include "core/mp/meta.h"

namespace core::tp
{

namespace detail
{
template<typename T, typename... Is>
auto impl(T const& tuple, mp::list<Is...>)
{ return std::make_tuple(std::get<Is::value>(tuple)...); }
};

template<typename S, typename T, typename U>
auto permute(U const& tuple)
{
    using Index = mp::permutation_t<S,T>;
    return detail::impl(tuple, Index{});
}

}; // tp
    
#endif
