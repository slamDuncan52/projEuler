def pal_check(val):
    if len(val) == 0 or len(val) == 1 :
        return True
    if val[0] != val[-1] :
        return False

    return pal_check(val[1:-1])

def main():
    res = 0
    for a in range(999, 99, -1):
        for b in range(a, 99, -1):
            c = a*b
            if pal_check(str(c)) and c > res:
                res = c
    
    print(res)
            
if __name__ == "__main__":
    main()
