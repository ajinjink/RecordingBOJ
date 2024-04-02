import sys
input = sys.stdin.readline

k = int(input())

for i in range(k):
    n, s, d = map(int, input().split())
    dc = 0
    for j in range(n):
        di, vi = map(int, input().split())
        if d * s >= di:
            dc += vi
    print(f"Data Set {i + 1}:")
    print(dc)
    print()