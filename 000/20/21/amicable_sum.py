import math as m

def sum_prop_div(num):
    divs = [1]
    for i in range(2, m.floor(m.sqrt(num))+1):
            if(num / i == num//i):
                divs.append(i)
                divs.append(num//i)
    return sum(divs)

def amicable(num):
    forward = sum_prop_div(num)
    backward = sum_prop_div(forward)

    if((num == backward) and (forward != backward)):
        return num
    else:
        return 0

def main():
    res = [amicable(x) for x in range(1,10000)]
    print(sum(res))

if __name__ == "__main__":
        main()
