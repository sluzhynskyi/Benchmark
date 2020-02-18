
import string
import argparse
import sys
import subprocess
from collections import defaultdict
from math import inf
# from functools import reduce
NUM_METHODS = 3


def count_symbols(filename: str) -> int:
    with open(filename, "r") as f:

        return sum((0 if i in string.whitespace else 1 for i in f.read()))
        # return reduce(lambda y, z: y + (0 if z in string.whitespace else 1), f.read(), 0)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Benchmarking a C++ program")
    parser.add_argument(
        "num_runs", help="Number of function calls for each type", type=int)
    parser.add_argument("in_file", help="Input file path")
    parser.add_argument("out_file", help="Input file path")
    args = parser.parse_args(sys.argv[1:])

    try:
        open(args.in_file).close()
    except FileNotFoundError:
        print("Input file not found!")
        quit(-1)
    # Create or clear output file
    open(args.out_file, "w").close()

    best_times = defaultdict(lambda: inf)
    print(f"{'Reading file, using:':30}Best time(us):")

    for method_id in range(NUM_METHODS):
        for _ in range(args.num_runs):

            with subprocess.Popen(f"build/Benchmark.exe {method_id+1} {args.in_file} {args.out_file}", stdout=subprocess.PIPE) as prog:
                output = prog.stdout.read().decode("utf_8")
                method_time = int(output.split("\n")[-1])
                best_times[method_id] = min(best_times[method_id], method_time)
            method_name = output.split("using ")[1].split(
                " (microseconds)")[0]+":"
        print(f"{method_name:30}{method_time}")

    num_symbols = count_symbols(args.in_file)
    errors = 0

    with open(args.out_file) as f:
        for line in f.readlines():
            if(int(line.split(": ")[-1]) != num_symbols):
                errors += 1

    print("All results are the same " if(errors == 0)
          else f"Errors encountered:{errors}")
