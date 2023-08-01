import sys
input = sys.stdin.readline

for i in range(int(input())):
    l = list(map(int, input().split()))
    n = l[0]
    arr = l[1:]
    res = []
    for j in range(n):
        res.append(arr[j] * (n - j))
    print(f"Case {i + 1}: {n - 1}", *res)