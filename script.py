
import string
import argparse
import sys
import subprocess
# from functools import reduce
NUM_METHODS = 3

def count_symbols(filename:str)->int:
    with open(filename, "r") as f:
        
        return sum((0 if i in string.whitespace else 1 for i in f.read()))
        # return reduce(lambda y, z: y + (0 if z in string.whitespace else 1), f.read(), 0)
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Benchmarking a C++ program")
    parser.add_argument("num_runs", help="Number of function calls for each type", type=int)
    parser.add_argument("in_file", help="Input file path")
    parser.add_argument("out_file", help="Input file path")
    args = parser.parse_args(sys.argv[1:])
    # //print(args.num_runs)
    try:
        open(args.in_file).close()
    except FileNotFoundError:
        print("Input file not found!")
    
    for method in range(NUM_METHODS):
        with subprocess.Popen(f"build/Benchmark.exe {method+1} {args.in_file} {args.out_file}", stdout=subprocess.PIPE) as prog:
            output = prog.stdout.read()
            print(output)
