import math as m

def main():
    lo = 1
    hi = 2000000
    vals = [True for x in range(lo, hi+1)]
    for x in range(lo+1, hi):
        if(vals[x] == True):
            for y in range(2*x, hi, x):
                vals[y] = False

    primes = [x[0] for x in enumerate(vals) if x[1]]
    print(sum(primes)-1)
    
if __name__ == "__main__":
    main()
