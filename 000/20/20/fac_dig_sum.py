def sumDig(num):
    total = 0
    while(num > 0):
        part = num % 10
        num = num // 10
        total += part
    return total

def fac(num):
    total = 1
    while(num > 0):
        total = total * num
        num -= 1
    return total

def main():
    f_val = fac(100)
    print(f_val)
    final = sumDig(f_val)
    print(final)

if __name__ == "__main__":
    main()
