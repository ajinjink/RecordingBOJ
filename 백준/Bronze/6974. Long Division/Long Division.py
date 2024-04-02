import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    a = int(input())
    b = int(input())
    mod = a % b
    print((a - mod) // b)
    print(mod)
    print()