import functools as f
import math as m

def pal_check(val):
    if(len(val) == 0 or len(val) == 1):
        return True
    if(val[0] != val[-1]):
        return False
    return pal_check(val[1:-1])

def bin_convert(dec):
    res = ""
    limit = int(m.log(dec, 2))
    while(limit >= 0):
        cur = m.pow(2,limit)
        if(dec - cur >= 0):
            dec -= cur
            res += "1"
        else:
            res += "0"
        limit -= 1

    return res

def main():
    limit = 1000000
    vals = [(x,bin_convert(x)) for x in range(1,limit) if pal_check(str(x))]
    res = f.reduce(lambda a,b: a+b[0], filter(lambda x: pal_check(x[1]), vals), 0)
    print(res)

if __name__ == "__main__":
    main()
