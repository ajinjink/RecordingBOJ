import sys
input = sys.stdin.readline

while True:
    n = int(input())
    if n == -1:
        break
    sum, prev = 0, 0
    for _ in range(n):
        a, b = map(int, input().split())
        sum += a * (b - prev)
        prev = b
    print(sum, "miles")