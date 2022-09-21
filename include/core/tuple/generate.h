// Copyright (C) 2017, 2019, 2021, 2022 by Mark Melton
//

#pragma once

#include <tuple>
#include "core/mp/list.h"
#include "core/mp/generate.h"

namespace core::tp {

/// Evaluates to type `std::tuple` with **N** elements of type **T**.
///
/// \tparam T The type of each typle element.
/// \tparam N The number of tuple elements.
template<class T, size_t N>
using generate_t = core::mp::rename_t<core::mp::generate_t<T, N>, std::tuple>;

};
