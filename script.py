
import string

def count_symbols(filename:str)->int:
    with open(filename, "r") as f:
        return sum((0 if i in string.whitespace else 1 for i in f.read()))



if __name__ == "__main__":
    pass