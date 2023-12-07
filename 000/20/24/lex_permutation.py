def fac(n):
    if n == 0: return 1
    return n * fac(n-1)

def all_perms(length):
    res = []
    for i in range(fac(length)):
        chars = [str(i) for i in range(length)]
        res.append(perms_recur(i, length-1, chars, ""))
    return res

def perm_index(index, length):
    return perms_recur(index, length-1, [str(i) for i in range(length)], "")

def perms_recur(index, length, chars, res):
    if(length == -1):
        return res
    res += chars.pop(index//fac(length))
    return perms_recur(index % fac(length), length-1, chars, res)

def main():
    print(perm_index(999999,10))

if __name__ == "__main__":
    main()
