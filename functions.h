//
// Created by sluzh on 16/02/2020.
//
#ifndef BENCHMARK_FUNCTIONS_H
#define BENCHMARK_FUNCTIONS_H

#include <fstream>
#include<sstream>
#include <string>

//template<typename CharT>
//std::basic_string<char, std::char_traits<CharT>, std::allocator<CharT>> best(std::basic_ifstream<char> );
std::string best(std::ifstream &);

std::string using_iterators(std::ifstream &);

template <typename Container = std::string,
        typename CharT = char,
        typename Traits = std::char_traits<char>>
std::string read_file_into_memory(
        std::basic_ifstream<CharT, Traits>&,
        typename Container::allocator_type alloc = {});

#endif //BENCHMARK_FUNCTIONS_H
