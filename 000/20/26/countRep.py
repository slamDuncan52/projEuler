def primesUnderK(k):
    vals = [True for x in range(k)]
    vals[0] = False
    vals[1] = False
    for x in range(2, k):
        if vals[x]:
            for y in range(2*x, k, x):
                vals[y] = False
    return [x[0] for x in enumerate(vals) if x[1]]

def primeDecimalCycleLength(x):
    if x == 2 or x == 5:
        return 0
    k = 1
    while(((10**k) - 1) % x != 0):
        k += 1
    return k

def main():
    limit = 1000
    primes = primesUnderK(limit)
    reps = [primeDecimalCycleLength(n) for n in primes]
    print("(length, prime)")
    print(max(list(zip(reps,primes))))

if __name__ == "__main__":
    main()
