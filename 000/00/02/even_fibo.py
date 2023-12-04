import functools as f

def fibo_under_k(num):
    res = [1,2]
    while(max(res) < num):
        res.append(res[-1] + res[-2])
    
    return res

def main():
    limit = 4000000
    res = f.reduce(lambda a,b: a+b, filter(lambda a: a % 2 == 0, fibo_under_k(limit)))
    print(res)

if __name__ == "__main__":
    main()
