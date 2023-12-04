def factorial(num):
    if(num == 0):
        return 1
    else:
        return num * factorial(num-1)

def main():
    size = 20
    part = factorial(size)
    res = (factorial(2*size) / (part * part))
    print(int(res))

if __name__ == "__main__":
    main()
