import sys
import random

def randNum():
    return random.randint(0,3)

if __name__ == "__main__":
    iterations = int(sys.argv[1])
    p = open("nums.txt", "w+")
    for x in range(0, iterations):
        num = randNum()
        p.write(str(num))
    p.close()
        
