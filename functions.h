//
// Created by sluzh on 16/02/2020.
//
#include <fstream>

#ifndef BENCHMARK_FUNCTIONS_H
#define BENCHMARK_FUNCTIONS_H


//template<typename CharT>
//std::basic_string<char, std::char_traits<CharT>, std::allocator<CharT>> best(std::basic_ifstream<char> );
std::string best(std::ifstream&);
std::string using_iterators(std::ifstream&);
#endif //BENCHMARK_FUNCTIONS_H
