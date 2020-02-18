//
// Created by sluzh on 16/02/2020.
//
#include <iostream>
#include<string>
#include<sstream>
#include <fstream>
#include <vector>
#include <limits>
#include "functions.h"

std::string best(std::ifstream &in) {
    auto ss = std::ostringstream{};
    if (!(ss << in.rdbuf())) {
        throw std::ios_base::failure{"error"};
    }
    return ss.str();
};


std::string using_iterators(std::ifstream &in) {
    return std::string{std::istreambuf_iterator<char>{in},
                       std::istreambuf_iterator<char>{}};
}

std::string for_large_files(std::ifstream &in) {
    auto const start_pos = in.tellg();
    in.ignore(std::numeric_limits<std::streamsize>::max());
    auto const char_count = in.gcount();
    in.seekg(start_pos);
    auto s = std::string(char_count, char{});
// or std::vector<char>(char_count);
// or you can use unsigned char or signed char
    in.read(&s[0], s.size());
    return s;
}