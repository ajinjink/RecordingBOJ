import sys
input = sys.stdin.readline

k = int(input())
for i in range(k):
    c, b, n, r = map(int, input().split())
    bc = list(map(int, input().split()))
    dic = {}
    res = 0
    for _ in range(n):
        cp, bp = map(int, input().split())
        dic[cp] = dic.get(cp, 0) + bp * r // 100
    for b in bc:
        res += dic.get(b, 0)
    print(f"Data Set {i + 1}:")
    print(res, '\n')