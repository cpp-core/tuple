// Copyright (C) 2018, 2019, 2022 by Mark Melton
//

#pragma once

#include "core/util/common.h"
#include "core/mp/list.h"
#include "core/mp/at.h"
#include "core/string/lexical_cast.h"

namespace core::tp {

template<typename T, std::size_t... Is>
mp::rename_t<T,std::tuple> parse(const string_views& views, std::index_sequence<Is...>)
{ return { core::lexical_cast<mp::at_ct<Is,T>>(views[Is])... }; }

template<typename T, std::size_t N = mp::size_v<T>>
mp::rename_t<T,std::tuple> parse(const string_views& vec)
{ return parse<T>(vec, std::make_index_sequence<N>{}); }

}; // end namespace tuple
