with open("infile.txt", "r") as f:
    str_file = f.read()
    print(str_file.count(" "))
    print(len(str_file))
