import sys
input = sys.stdin.readline

def f(a, b, n):
    if b == 0:
        return n - 1
    return f(b, a % b, a // b + n)

a, b = map(int, input().split())
print(f(a, b, 0))