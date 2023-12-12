from math import sqrt

def primesUnderK(k):
    vals = [True for x in range(k)]
    vals[0] = False
    vals[1] = False
    for x in range(2, k):
        if vals[x]:
            for y in range(2*x, k, x):
                vals[y] = False
    return [x[0] for x in enumerate(vals) if x[1]]

def primeTest(k):
    if(k < 2):
        return False
    limit = int(sqrt(k)) + 1
    testVals = primesUnderK(limit)
    for v in testVals:
        if k % v == 0:
            return False
    return True

def quadTest(a, b):
    #primes = primesUnderK(b*(b+a+1))
    n = 0
    while(True):
        val = n**2 + a*n + b
        if primeTest(val) == False:
        #if val not in primes:
            return n
        n += 1
    

def main():
    limit = 1000
    max_seen = 0
    max_a = 0
    max_b = 0
    legal_bs = primesUnderK(limit)
    for b in legal_bs:
        for a in range(-limit+1, limit):
            val = quadTest(a,b)
            if val > max_seen:
                max_seen = val
                max_a = a
                max_b = b
    print("Max Consecutive Primes:", max_seen)
    print("Max A and B:", max_a, max_b)
    print("Max product:", max_a*max_b)
    

if __name__ == "__main__":
    main()

