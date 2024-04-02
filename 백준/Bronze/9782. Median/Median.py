import sys
input = sys.stdin.readline

c = 1
while True:
    l = list(map(int, input().split()))
    n = l[0]
    if n == 0:
        break
    res = 0
    if n % 2 == 1:
        res = l[int((n + 1)/2)]
    else:
        res = (l[int(n / 2)] + l[int(n / 2) + 1]) / 2
    print(f"Case {c}: {res:.1f}")
    c += 1

