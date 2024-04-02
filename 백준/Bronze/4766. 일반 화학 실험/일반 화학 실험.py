import sys
input = sys.stdin.readline

prev = float(input())
while True:
    n = float(input())
    if n == 999:
        break
    print(f"{(n - prev):.2f}")
    prev = n