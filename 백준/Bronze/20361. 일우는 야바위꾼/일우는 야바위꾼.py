import sys
input = sys.stdin.readline

n, x, k = map(int, input().split())
l = [i for i in range(1, n + 1)]
change = [list(map(int, input().split())) for _ in range(k)]
for s in change:
    l[s[0] - 1], l[s[1] - 1] = l[s[1] - 1], l[s[0] - 1]
print(l.index(x) + 1)