import sys

x, y, w, h = map(int, sys.stdin.readline().split())

res = []
res.append(x)
res.append(y)
res.append(w - x)
res.append(h - y)

print(min(res))