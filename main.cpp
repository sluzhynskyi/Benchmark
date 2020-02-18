#include <iostream>
#include<string>
#include<sstream>
#include <fstream>
#include "functions.h"

using namespace std;

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
    switch (method_ind) {
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
            std::cout << "invalid method name!";
    }
    s = best(in);


    int symbols = 0;
    for (auto ch:s) {
        if (!std::isspace(ch)) {
            symbols += 1;
        }
    }
//    std::ofstream out;
//    out.open(file_out, ios::out);
    std::ofstream out(file_out);
    if (!out) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    out << symbols;

    return 0;

}