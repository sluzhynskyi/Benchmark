#include <iostream>
#include<string>
#include<sstream>
#include <fstream>
#include "functions.h"

using namespace std;

typedef int (*Functions)(int a);


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

    auto s = best(in);
    cout << s << endl;
    return 0;

}