#include <iostream>
#include<string>
#include<sstream>
#include <fstream>
#include "functions.h"

using namespace std;

// typedef int (*Functions)(int a);
#include <chrono>
#include <atomic>

inline std::chrono::high_resolution_clock::time_point get_current_time_fenced()
{
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template<class D>
inline long long to_us(const D& d)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}

int main(int argc, char **argv) {
    // Reading variables from terminal
    int method_ind = std::stoi(argv[1]);
    string file_in = argv[2];
    string file_out = argv[3];

    // Reading file
    cout << file_in.c_str() << endl;
    std::ifstream in(file_in.c_str());
    if (!in) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    std::string method_description;
    std::string s;
    auto starting_time = get_current_time_fenced();
    // switch/case doesn't take much time
    switch(method_ind){
        case 1:
            method_description = "ss<<in.rdbuf()";
            s = best(in);
            break;
        case 2:
            method_description = "istreambuf_iterator{in}";
            s = using_iterators(in);
            break;
        case 3:
            method_description = "Method 3";
            s = read_file_into_memory(in);
            break;
        default:
            std::cout<<"invalid method name!";
    }
    auto duration = get_current_time_fenced() - starting_time;

    int symbols = 0;
    for(auto ch:s){
        if(!std::isspace(ch)){
            symbols+=1;
        }
    }
//    std::ofstream out;
//    out.open(file_out, ios::out);
    std::ofstream out(file_out);
    if (!out) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    out<<"\""<<method_description<<"\": "<<symbols;

    std::cout<<"Reading file using"<<method_description<<"(microseconds):"<<std::endl<<to_us(duration);

    return 0;

}