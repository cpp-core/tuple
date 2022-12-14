// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#ifndef CORE_TUPLE_LIST_IMPL_H
#define CORE_TUPLE_LIST_IMPL_H

#include <tuple>

namespace core::tp {
namespace impl {

// car, cdr, cons implementation
//
template<size_t... Xs>
struct sequence
{
    template<size_t X>
    using cons = sequence<X, Xs...>;
};

template<size_t start, size_t end>
struct range
{
    static_assert(start < end, "Range: start > end");
    using type = typename range<start + 1, end>::type::template cons<start>;
};

template<size_t start>
struct range<start, start>
{
    using type = sequence<>;
};

}; // end namespace impl
}; // end namespace core::tp

#endif
