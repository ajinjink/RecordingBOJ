import sys
input = sys.stdin.readline

q = int(input())
l = []
for _ in range(q):
    l.append(input().strip())
r = int(input())
for _ in range(r):
    n = int(input())
    if 0 < n <= q:
        print(f"Rule {n}: {l[n - 1]}")
    else:
        print(f"Rule {n}: No such rule")