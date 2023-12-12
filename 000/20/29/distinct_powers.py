lo = 2
hi = 100
group = range(lo,hi+1)
res = []
for a in group:
    for b in group:
            res.append(a**b)
print(len(set(res)))
