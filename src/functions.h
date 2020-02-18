//
// Created by sluzh on 16/02/2020.
//
#ifndef BENCHMARK_FUNCTIONS_H
#define BENCHMARK_FUNCTIONS_H

#include <fstream>
#include<sstream>
#include <string>
#include <memory>

//template<typename CharT>
//std::basic_string<char, std::char_traits<CharT>, std::allocator<CharT>> best(std::basic_ifstream<char> );
std::string best(std::ifstream &);

std::string using_iterators(std::ifstream &);

std::string for_large_files(std::ifstream &);
#endif //BENCHMARK_FUNCTIONS_H
