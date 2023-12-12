def main():
    k = 1001
    corner_vals = [1] + [2*n*(2*n-3)+6 for n in range(3, k+1, 2)]
    print(sum(corner_vals))

if __name__ == "__main__":
    main()

