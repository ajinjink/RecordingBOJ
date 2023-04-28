import sys

dish = sys.stdin.readline().rstrip()

prev = dish[0]
res = 10
for i in range(1, len(dish)):
    if dish[i] == prev:
        res += 5
    else:
        res += 10
    prev = dish[i]

print(res)

