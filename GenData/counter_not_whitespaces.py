import string

with open("infile.txt", "r") as f:
    str_file = f.read()
    counter = 0
    for i in str_file:
        if i not in string.whitespace:
            counter += 1
    print(f"The number symbols that are not whitespaces is: {counter}")
