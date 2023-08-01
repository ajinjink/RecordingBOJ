import sys
input = sys.stdin.readline

h, w = map(int, input().split())
if h < w:
    h, w = w, h
res1 = h / 3 if h / 3 <= w else w
res2 = w / 2
print(max(res1, res2))