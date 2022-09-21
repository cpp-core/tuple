// Copyright (C) 2022 by Mark Melton
//

#include <iostream>
#include "core/tuple/map.h"

template<class F, class... Ts>
requires std::is_same_v<void, std::invoke_result_t<F, std::add_lvalue_reference_t<std::tuple_element_t<0, Ts>>...>>
auto mapper(F&& function, Ts&... tuples) {
    std::cout << "void mapper" << std::endl;
}

template<class F, class... Ts>
requires (!std::is_same_v<void, std::invoke_result_t<F, std::tuple_element_t<0, Ts>...>>)
auto mapper(F&& function, Ts&... tuples) {
    std::cout << "non-void mapper" << std::endl;
}

int main(int argc, const char *argv[]) {
    auto tup = std::make_tuple(5);
    // mapper([](int& n) { }, tup);
    // mapper([](int& n) { return n; }, tup);

    auto get_element = [&](int x) { };
    std::cout << std::is_same_v<decltype(get_element(0)), void> << std::endl;
    return 0;
}
