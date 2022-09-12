// Copyright (C) 2017, 2019, 2021 by Mark Melton
//

#pragma once

#include <tuple>
#include "core/mp/list.h"
#include "core/mp/generate.h"

namespace core::tp {

// Evaluates to a **std::tuple<...>** with `N` elements of type `T`.
template<class T, size_t N>
using generate_t = core::mp::rename_t<core::mp::generate_t<T, N>, std::tuple>;

};
