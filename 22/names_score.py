def main():
    with open("names.txt", "r") as inf:
        val = inf.read()
        names = [x[1:-1] for x in val.split(',')]

    names.sort()
    vals = [sum(map(lambda x: ord(x)-ord('A')+1, s)) for s in names]
    
    final = [(x[0]+1) * x[1] for x in enumerate(vals)]
    print(sum(final))

if __name__ == "__main__":
    main()
