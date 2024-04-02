import sys
input = sys.stdin.readline

f, a = map(int, input().split())
n = int(input())
for _ in range(n):
    c = int(input())
    print(c, f*c if c <= 1000 else 1000*f+(c-1000)*a)