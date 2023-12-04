import math as m
from functools import reduce

def primeSieve(num, primes):
    for p in primes:
        if(num / p == num // p):
            return False
    return True

def main():
    target = 20
    primes = [2]
    current = 3
    while(max(primes) < target):
        if(primeSieve(current, primes)):
            primes.append(current)
        current += 1
    
    pairs = [(x,int(m.log(target,x))) for x in primes]
    val = reduce(lambda a,b: a*m.pow(b[0],b[1]), pairs, 1)
    print(int(val))

if __name__ == "__main__":
    main()

