import sys
input = sys.stdin.readline

i = 1
while True:
    n = int(input())
    if n < 0:
        break
    X, Y, M = 0, 0, 0
    for _ in range(n):
        x, y, m = map(float, input().split())
        X += x * m
        Y += y * m
        M += m
    input()
    print(f"Case {i:d}: {(X / M):.2f} {(Y / M):.2f}")
    i += 1