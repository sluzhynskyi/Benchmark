<<<<<<< HEAD
import random
import string

n = 1024 ** 2  # 1 Mb of text
chars = ''.join([random.choice(string.printable) for i in range(n)])
with open('infile.txt', 'w+') as f:
    f.write(chars)

=======
import random
import string

n = 1024 ** 2  # 1 Mb of text
chars = ''.join([random.choice(string.printable) for i in range(n)])
with open('infile.txt', 'w+') as f:
    f.write(chars)

>>>>>>> aca3b45a8b028412603c42c4644e750b6ccfe1d3
