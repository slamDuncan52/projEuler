import math as m

def pythag_check(a, b):
    c = m.sqrt(a*a + b*b)
    if(c == int(c)):
        return int(c)
    else:
        return -1

def main():
    hi = 1000
    target = 1000
    for a in range(1,hi):
        for b in range(a, hi-a):
            c = pythag_check(a,b)
            if(c != -1):
                if(a+b+c == target):
                    print(a*b*c)

if __name__ == "__main__":
    main()
