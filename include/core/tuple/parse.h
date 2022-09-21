// Copyright (C) 2018, 2019, 2022 by Mark Melton
//

#pragma once

#include <string_view>
#include "core/mp/list.h"
#include "core/mp/at.h"

namespace core::tp {

template<typename T, std::size_t... Is>
mp::rename_t<T,std::tuple> parse(const std::vector<std::string_view>& views,
				 std::index_sequence<Is...>) {
    return { core::str::lexical_cast<mp::at_ct<Is,T>>(views[Is])... };
}

/// Create a new tuple by parsing the given string_view's according to
/// the type of the coresponding tuple element.
///
/// This function requires the *cxx_core_string* library to be
/// installed in order to parse the individual elements.
///
/// \tparam T The type of tuple to create.
/// \tparam N The tuple arity.
template<typename T, std::size_t N = mp::size_v<T>>
mp::rename_t<T,std::tuple> parse(const std::vector<std::string_view>& vec) {
    return parse<T>(vec, std::make_index_sequence<N>{});
}

}; // end namespace tuple
