import math as m

def primeSieve(num, primes):
    for p in primes:
        if(num / p == num // p):
            return False
    return True

def main():
    target = 10001
    primes = [2]
    current = 3
    while(len(primes) < target):
        if(primeSieve(current, primes)):
            primes.append(current)
        current += 1

    print(primes[-1])
    
if __name__ == "__main__":
    main()
