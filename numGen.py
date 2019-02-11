# Chris Myers
# I wrote all my code.
# I did not show my code

import sys
import random

def rNum():
    return random.randint(0,3)
if __name__ == "__main__":
    iterations = int(sys.argv[1])
    p = open("inputnum.txt", "w+")
    for x in range(0, iterations):
        number = rNum()
        p.write(str(number))
    p.close()