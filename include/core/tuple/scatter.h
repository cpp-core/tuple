// Copyright (C) 2017, 2019 by Mark Melton
//

#pragma once
#include "core/mp/list.h"

namespace core::tp
{

template<class T, class U, class... Is>
void scatter(T const& source, U& target, core::mp::list<Is...>)
{
    size_t idx{0};
    ((target[Is::value] = source[idx++]), ...);
}

}; // tp
