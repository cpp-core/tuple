// Copyright (C) 2017, 2019, 2021 by Mark Melton
//

#ifndef CORE_TUPLE_TUPLES_H
#define CORE_TUPLE_TUPLES_H

#include <tuple>
#include "core/mp/list.h"
#include "core/mp/generate.h"

using Tuple1n = mp_rename_t<mp::generate_t<size_t,1>,std::tuple>;
using Tuple2n = mp_rename_t<mp::generate_t<size_t,2>,std::tuple>;
using Tuple3n = mp_rename_t<mp::generate_t<size_t,3>,std::tuple>;
using Tuple4n = mp_rename_t<mp::generate_t<size_t,4>,std::tuple>;

using Tuple1i = mp_rename_t<mp::generate_t<integer,1>,std::tuple>;
using Tuple2i = mp_rename_t<mp::generate_t<integer,2>,std::tuple>;
using Tuple3i = mp_rename_t<mp::generate_t<integer,3>,std::tuple>;
using Tuple4i = mp_rename_t<mp::generate_t<integer,4>,std::tuple>;

#endif
