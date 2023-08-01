import sys
input = sys.stdin.readline

for i in range(int(input())):
    n, w, e = map(int, input().split())
    res = 0
    for _ in range(n):
        ww, we, ew, ee = map(int, input().split())
        res += max(ww*w + ew*e, e*ee + we*w)
    print(f"Data Set {i + 1}:")
    print(res)
    print()