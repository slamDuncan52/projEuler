# Find the sum of all positive integers which cannot be written as the sum of two abundant numbers
# Find all positive integers which cannot be written as the sum of two abundant numbers
#Analytically, we know that all numbers > 28123 can be written as the sum of two abundant numbers
#We only need to check numbers from 24 to 28123 as being sums of two abundant numbers
#We only need to check numbers 12 to 28123 as being abundant

#KEY ALGORITHM: Finding all proper divisors of a number
#Use sieve?

import math as m

def propFac(num):
    divs = [1]
    #candidates = list(range(2,m.ceil(m.sqrt(num))))
    for i in range(2, m.floor(m.sqrt(num))+1):
        if(num / i == num//i):
            divs.append(i)
            divs.append(num//i)
    return set(divs)




def allAbundSums(abund):
    res = []
    for val in abund:
        for pair in abund:
            if(val+pair < 28124):
                res.append(val+pair)
    return set(res)

def main():
    lo = 1
    hi = 28124
    abund = [x for x in range(lo,hi) if sum(propFac(x)) > x]
    #print(abund)
    res = allAbundSums(abund)
    #print(res)
    full = set(range(lo,hi))
    print(sum(full-res))

if __name__ == "__main__":
    main()
