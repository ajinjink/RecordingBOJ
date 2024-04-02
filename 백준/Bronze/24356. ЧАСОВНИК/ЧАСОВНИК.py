import sys
input = sys.stdin.readline

a, b, c, d = map(int, input().split())

if a * 60 + b > c * 60 + d:
    c += 24

print((c * 60 + d) - (a * 60 + b), ((c * 60 + d) - (a * 60 + b)) // 30)