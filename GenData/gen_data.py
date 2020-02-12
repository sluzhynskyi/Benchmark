import random
import string

n = 1024 ** 2  # 1 Mb of text
chars = ''.join([random.choice(string.printable) for i in range(n)])
with open('infile.txt', 'w+') as f:
    f.write(chars)

