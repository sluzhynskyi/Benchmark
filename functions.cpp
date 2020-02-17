//
// Created by sluzh on 16/02/2020.
//
#include <iostream>
#include<string>
#include<sstream>
#include <fstream>
#include "functions.h"

std::string best(std::ifstream in) {
    auto ss = std::ostringstream{};
    if (!(ss << in.rdbuf())) {
        throw std::ios_base::failure{"error"};
    }
    return ss.str();
};

template<typename CharT, typename Traits, typename Allocator = std::allocator<CharT>>
static auto read_stream_into_string(std::basic_istream<CharT, Traits> &in, Allocator alloc = {}) {
    std::basic_ostringstream<CharT, Traits, Allocator>
            ss(std::basic_string<CharT, Traits, Allocator>(std::move(alloc)));

    if (!(ss << in.rdbuf())) {
        throw std::ios_base::failure{"error"};
    }
    return ss.str();
}