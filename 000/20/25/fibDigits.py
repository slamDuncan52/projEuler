def countDigits(n):
    if n == 0: return 1
    count = 0
    while n > 0:
        count += 1
        n //= 10
    return count

def fibonacci(limit):
    res = [1,1]
    cur = 2
    while limit > cur:
        res.append(res[cur-2] + res[cur-1])
        cur += 1
    return res

def printLenIndexes(fiblens):
    counting = enumerate(fiblens)
    upindexes = []
    prevval = 0
    for(index, val) in counting:
        if prevval != val:
            upindexes.append(index+1)
            prevval = val
    return upindexes

def countFiveDistance(fiveDifs):
    curCount = 0
    for x,y in enumerate(fiveDifs):
        if y == 5:
            curCount += 1
        else:
            print((x,curCount))
            curCount = 0

def main():
    limit = 5000
    fibnums = fibonacci(limit)
    fiblens = [countDigits(x) for x in fibnums]
    indexes = printLenIndexes(fiblens)
    print(indexes[999])

if __name__ == "__main__":
    main()
