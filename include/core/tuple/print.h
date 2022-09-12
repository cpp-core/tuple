// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#ifndef CORE_TUPLE_PRINT_H
#define CORE_TUPLE_PRINT_H

#include <tuple>
#include <iostream>
#include "core/tuple/apply.h"

namespace core::tp {

struct printer
{
    printer(std::ostream& os, std::string const& sep = ",") : m_os(os), m_sep(sep) { }
    mutable std::ptrdiff_t m_index = 0;
    std::ostream& m_os;
    std::string m_sep;
    
    template<typename T>
    void operator()(T const& value) const
    {
	if (m_index > 0)
	    m_os << m_sep;
	m_os << value;
	++m_index;
    }

    void operator()(std::vector<double> const& values) const
    {
	for (auto x : values)
	{
	    if (m_index > 0)
		m_os << m_sep;
	    m_os << x;
	    ++m_index;
	}
    }
};

template<typename... Ts>
void print(std::ostream& os, std::tuple<Ts...> const& tup, std::string const& sep = ",")
{
    core::tp::printer p(os, sep);
    core::tp::apply(p, tup);
}

}; // end namespace core::tp

template<typename... Ts>
std::ostream& operator<<(std::ostream& os, std::tuple<Ts...> const& tup)
{
    core::tp::printer p(os);
    core::tp::apply(p, tup);
    return os;
}

#endif
