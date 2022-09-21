// Copyright (C) 2022 by Mark Melton
//

#include <iostream>

int main(int argc, const char *argv[]) {
    auto get_element = [&](int x) { };
    std::cout << std::is_same_v<decltype(get_element(0)), void> << std::endl;
    return 0;
}
