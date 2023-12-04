def main():
    target = 100
    vals = [x for x in range(1,target+1)]
    num_a = sum([x*x for x in vals])
    num_b = sum(vals) * sum(vals)
    print(num_b - num_a)

if __name__ == "__main__":
    main()
