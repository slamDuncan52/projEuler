import math as m

def factors(num):
    return factors_help(num, [], primes_under_k(int(m.sqrt(num))))

def factors_help(num, res, primes):
    if(num == 1):
        return res

    for p in reversed(primes):
        if(num / p == num // p):
            res.append(p)
            num = num // p
            break
    
    return factors_help(num, res, primes)

def primes_under_k(hi):
    lo = 1
    vals = [True for x in range(lo, hi+1)]
    vals[0] = False
    vals[1] = False

    for x in range(lo+1, hi):
        if(vals[x] == True):
            for y in range(2*x, hi, x):
                vals[y] = False
    primes = [x[0] for x in enumerate(vals) if x[1]]
    return primes


def main():
    goal = 600851475143
    print(factors(goal)[0])

    
if __name__ == "__main__":
    main()
