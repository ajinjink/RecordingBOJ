import sys
input = sys.stdin.readline

while True:
    n = int(input())
    if n == 0:
        break
    a, b, c = map(int, input().split())
    if b - a == c - b:
        print(n * (2 * a + (n - 1) * (b - a)) // 2)
    else:
        print(int(a * ((b / a)**n - 1) / (b / a - 1)))