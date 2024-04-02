import sys
input = sys.stdin.readline

d = list(map(int, input().split()))
res = []
for _ in range(int(input())):
    s = 0
    for _ in range(3):
        l = list(map(int, input().split()))
        for i in range(3):
            s += l[i] * d[i]
    res.append(s)
print(max(res))